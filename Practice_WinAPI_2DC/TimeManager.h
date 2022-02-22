#pragma once
class TimeManager
{
	SINGLETON(TimeManager);

private:
	LARGE_INTEGER	m_llCurCount;  /*���� ī��Ʈ*/
	LARGE_INTEGER   m_llPrevCount; /*���� ī��Ʈ*/
	LARGE_INTEGER   m_llFreq;      /*�ʴ� ī��Ʈ Ƚ��*/

	unsigned int	m_uiFPS; //FPS : 1�ʴ� �׷��� ȭ�� ��
	double			m_dDT; // Delta Time : 1�����Ӵ� �ҿ�� �ð�

public:
	void		 Update();  /*�� ������Ʈ�� fps,dt*/
	void		 Init();	/*timemanager �ʱ�ȭ��Ű��*/

	unsigned int GetFPS();
	double		 GetDT();
};

