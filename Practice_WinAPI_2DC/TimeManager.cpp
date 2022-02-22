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
	/*���� ������Ʈ ī��Ʈ�� ���� ������Ʈ ī��Ʈ ���� ���̸� ���ؼ�
	1�ʴ� ī��Ʈ ���� �����ָ�
	������Ʈ ������ �� �ʰ� �������� �˼� ����*/

	/*���� ������ ī���ð�, ���� ������ ī��Ƽ ���� ���̸� ���մϴ�.*/
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFreq.QuadPart;

	/*���� �������� ���� ������ ī���� ������ �ֽ��ϴ�.*/
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
	QueryPerformanceCounter(&m_llCurCount);		/*���� �ð��� ī��Ʈ ��*/    //SOLVED: ���⸦ ���� ī��Ʈ�� �ƴ� ���� ī��Ʈ�� ��, ������ ������.
	QueryPerformanceFrequency(&m_llFreq);	/*1�ʴ� �����ϴ� ī��Ʈ ��.*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}