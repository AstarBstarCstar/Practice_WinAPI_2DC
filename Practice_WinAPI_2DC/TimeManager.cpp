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
	/*���� ������Ʈ ī��Ʈ�� ���� ������Ʈ ī��Ʈ ���� ���̸� ���ؼ� 
	1�ʴ� ī��Ʈ ���� �����ָ� 
	������Ʈ ������ �� �ʰ� �������� �˼� ����*/
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
	QueryPerformanceCounter(&m_llPrevCount);		/*���� �ð��� ī��Ʈ ��*/
	QueryPerformanceFrequency(&m_llFreq);	/*1�ʴ� �����ϴ� ī��Ʈ ��*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}