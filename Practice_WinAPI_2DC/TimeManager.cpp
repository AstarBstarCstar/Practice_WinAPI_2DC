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
	static unsigned int UpdateCount = 0;//������Ʈ ī��Ʈ�� 0���� �ʱ�ȭ �մϴ�.
	static double UpdateOneSec = 0;//�ʴ� ���� �ð��� 0���� �ʱ�ȭ �մϴ�.

	QueryPerformanceCounter(&m_llCurCount);
	/*���� ������Ʈ ī��Ʈ�� ���� ������Ʈ ī��Ʈ ���� ���̸� ���ؼ�
	1�ʴ� ī��Ʈ ���� �����ָ�
	������Ʈ ������ �� �ʰ� �������� �˼� ����*/

	/*���� ������ ī���ð�, ���� ������ ī��Ƽ ���� ���̸� ���մϴ�.*/
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) /m_llFreq.QuadPart;

	/*���� �������� ���� ������ ī���� ������ �ֽ��ϴ�.*/
	m_llPrevCount = m_llCurCount;

	++UpdateCount;//������Ʈ ī��Ʈ�� 1 ������ŵ�ϴ�
	UpdateOneSec += m_dDT;//��Ÿ���� �ʴ� �����ð��� �ֽ��ϴ�.

	/*�ʴ������ð��� 1�ʺ��� �������
	������Ʈ ī��Ʈ�� fps�� �ְ� ������Ʈ ī��Ʈ���� �ʴ������ð��� 0���� �ʱ�ȭ �մϴ�.*/
	if (UpdateOneSec >= 1.0)
	{
		m_uiFPS = UpdateCount;

		UpdateOneSec = 0;
		UpdateCount = 0;
	}
}

void TimeManager::Init()
{/*UNKNOWN: ���� �����ս� �Լ��� �ڼ��� ��ɰ� �뵵*/
	QueryPerformanceCounter(&m_llPrevCount);		/*���� �ð��� ī��Ʈ ��*/    //SOLVED: ���� ī��Ʈ�� �ƴ϶� ���� ī��Ʈ�� �־���� ��.
	QueryPerformanceFrequency(&m_llFreq);				/*1�ʴ� �����ϴ� ī��Ʈ ��.*/
}
unsigned int TimeManager::GetFPS()
{
	return m_uiFPS;
}
double TimeManager::GetDT()
{
	return m_dDT;
}