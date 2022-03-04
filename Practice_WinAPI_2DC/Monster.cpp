#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	m_fCenterPos = (fPoint(0.f, 0.f));
	m_fSpeed = 300.f;
	m_fMaxDis = 500.f;
	m_iDir = 1;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	fPoint CurPos = GetPos(); //���� ������Ʈ Ŭ����(�θ�Ŭ����) ���� ��ġ�� �޾ƿɴϴ�.

	CurPos.x += m_fSpeed * m_iDir * fDT;//��Ÿ x ���ǵ� x ���� (������ 1�̸� ������ -1�̸� �������� ���ϴ�)

	float f_Dist =  abs(m_fCenterPos.x - CurPos.x) - m_fMaxDis ;//�Ÿ����� üũ ���ݴϴ�. f_Dist�� �ʰ���

	if (0.f < f_Dist)//��ȸ�Ÿ��� �ִ��� �Ѿ �� ������ �ٲپ� �ݴϴ�. 
	{
		m_iDir *= (-1);
		CurPos.x += f_Dist * m_iDir;//���� �ʰ����� �� �������ִ� �Լ��Դϴ�.
	}


	SetPos(CurPos);								//����� ���� SetPos ���ݴϴ�.
}
