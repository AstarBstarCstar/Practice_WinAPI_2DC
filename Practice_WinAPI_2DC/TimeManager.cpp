#include "framework.h"
#include "TimeManager.h"

TimeManager::TimeManager()
{
	m_llCurCount = {};
	m_llPrevCount = {};
	m_llFreq = {};
	m_uiFPS = 0;
	m_dDT = 0;
}
TimeManager::~TimeManager()
{
}

void TimeManager::Update()
{
	static unsigned int UpdateCount = 0;//업데이트 카운트를 0으로 초기화 합니다.
	static double UpdateOneSec = 0;//초당 지난 시간을 0으로 초기화 합니다.

	QueryPerformanceCounter(&m_llCurCount);
	/*이전 업데이트 카운트와 현재 업데이트 카운트 값의 차이를 구해서
	1초당 카운트 수로 나눠주면
	업데이트 사이의 몇 초가 지났는지 알수 있음*/

	/*이전 프레임 카운팅과, 현재 프레임 카운티 값의 차이를 구합니다.*/
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) /m_llFreq.QuadPart;

	/*이전 프레임을 현재 프레임 카운팅 값으로 넣습니다.*/
	m_llPrevCount = m_llCurCount;

	++UpdateCount;//업데이트 카운트를 1 증가시킵니다
	UpdateOneSec += m_dDT;//델타값을 초당 지난시간에 넣습니다.

	/*초당지난시간이 1초보다 빠른경우
	업데이트 카운트를 fps에 넣고 업데이트 카운트값과 초당지난시간을 0으로 초기화 합니다.*/
	if (UpdateOneSec >= 1.0)
	{
		m_uiFPS = UpdateCount;

		UpdateOneSec = 0;
		UpdateCount = 0;
	}
}

void TimeManager::Init()
{/*UNKNOWN: 쿼리 퍼포먼스 함수의 자세한 기능과 용도*/
	QueryPerformanceCounter(&m_llPrevCount);		/*현재 시간의 카운트 수*/    //SOLVED: 현재 카운트가 아니라 이전 카운트를 넣었어야 함.
	QueryPerformanceFrequency(&m_llFreq);				/*1초당 진행하는 카운트 수.*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}