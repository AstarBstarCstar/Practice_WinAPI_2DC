#include "TimeManager.h"
#include "framework.h"
TimeManager::TimeManager()
{
	//m_llCurCount = {};
	//m_llPrevCount = {};
	//m_llFreq = {};
	//m_uiFPS = 0;
	//m_dDT = 0;
}
TimeManager::~TimeManager()
{

}

void TimeManager::update()
{
	static unsigned int updateCount = 0;
	static double updateOneSec = 0;

	QueryPerformanceCounter(&m_llCurCount);
	/*이전 업데이트 카운트와 현재 업데이트 카운트 값의 차이를 구해서 
	1초당 카운트 수로 나눠주면 
	업데이트 사이의 몇 초가 지났는지 알수 있음*/
	m_dDt= (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFreq.QuadPart;
	m_llPrevCount = m_llCurCount;
	++updateCount;
	updateOneSec += m_dDT;
	if (updateOneSec >= 1.0)
	{
		m_uiFPS = updateCount;

		updateOneSec = 0;
		updateCount = 0;
	}
}
void TimeManager::init()
{
	QueryPerformanceCounter(&m_llPrevCount);		/*현재 시간의 카운트 수*/
	QueryPerformanceFrequency(&m_llFreq);	/*1초당 진행하는 카운트 수*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}