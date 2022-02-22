#include "framework.h"
#include "TimeManager.h"

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

void TimeManager::Update()
{
	static unsigned int UpdateCount = 0;
	static double UpdateOneSec = 0;

	QueryPerformanceCounter(&m_llCurCount);
	/*이전 업데이트 카운트와 현재 업데이트 카운트 값의 차이를 구해서
	1초당 카운트 수로 나눠주면
	업데이트 사이의 몇 초가 지났는지 알수 있음*/

	/*이전 프레임 카운팅과, 현재 프레임 카운티 값의 차이를 구합니다.*/
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFreq.QuadPart;

	/*이전 프레임을 현재 프레임 카운팅 값으로 넣습니다.*/
	m_llPrevCount = m_llCurCount;

	++UpdateCount;
	UpdateOneSec += m_dDT;

	if (UpdateOneSec >= 1.0)
	{
		m_uiFPS = UpdateCount;

		UpdateOneSec = 0;
		UpdateCount = 0;
	}
}

void TimeManager::Init()
{
	QueryPerformanceCounter(&m_llCurCount);		/*현재 시간의 카운트 수*/    //SOLVED: 여기를 현재 카운트가 아닌 이전 카운트로 썼어서, 에러가 났었음.
	QueryPerformanceFrequency(&m_llFreq);	/*1초당 진행하는 카운트 수.*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}