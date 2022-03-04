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
	fPoint CurPos = GetPos(); //게임 오브젝트 클래스(부모클래스) 에서 위치를 받아옵니다.

	CurPos.x += m_fSpeed * m_iDir * fDT;//델타 x 스피드 x 방향 (방향이 1이면 오른쪽 -1이면 왼쪽으로 갑니다)

	float f_Dist =  abs(m_fCenterPos.x - CurPos.x) - m_fMaxDis ;//거리값을 체크 해줍니다. f_Dist는 초과량

	if (0.f < f_Dist)//배회거리의 최댓값을 넘어갈 시 방향을 바꾸어 줍니다. 
	{
		m_iDir *= (-1);
		CurPos.x += f_Dist * m_iDir;//값이 초과했을 시 보정해주는 함수입니다.
	}


	SetPos(CurPos);								//변경된 값을 SetPos 해줍니다.
}
