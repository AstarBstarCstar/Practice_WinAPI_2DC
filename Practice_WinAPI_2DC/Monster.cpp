#include "framework.h"
#include "Monster.h"
#include "Bullet.h"
#include "Scene.h"
#include "Texture.h"
#include <time.h>
#include <stdlib.h>


class Scene;

Monster::Monster()
{
	srand(time(NULL));
	m_fCenterPos = (fPoint(0.f, 0.f));
	m_fSpeed = 300.f;
	m_fMaxDis = 500.f;
	m_iDir = 1;
	m_pMonTexture = ResourceManager::GetInst()->LoadTexture(L"Monster", L"texture\\Player.bmp");
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

	int shoot = rand() % 100 + 1;
	if (shoot >= 99)
	{ 
		ShootBullet();
	}
}

void Monster::Render(HDC _dc)
{
	int iWidth = m_pMonTexture->Width();
	int iHeigh = m_pMonTexture->Heigh();
	fPoint Pos = GetPos();
	/*BitBlt(_dc, Pos.x - int((float)(iWidth / 2)), int(Pos.y - (float)(iHeigh / 2)), iWidth, iHeigh, m_pMonTexture->GetDC(), 0, 0, SRCCOPY);*/
	TransparentBlt(_dc, Pos.x - int((float)(iWidth / 2)), int(Pos.y - (float)(iHeigh / 2)), iWidth, iHeigh, m_pMonTexture->GetDC(), 0, 0, iWidth, iHeigh, RGB(255, 0, 255));
}

void Monster::ShootBullet()
{
	
	fPoint vShootBullet = GetPos();
	vShootBullet.y -= GetScale().y-150;//TODO:몬스터 총알 랜덤으로 쏘게하기, 연산자 재정의 시전

	Bullet* pMBullet = new Bullet;
	pMBullet->SetPos(vShootBullet);
	pMBullet->SetScale(fPoint(10.f, 20.f));
	pMBullet->SetVec(fPoint(0, 1));

	Scene* MonScene = SceneManager::GetInst()->GetCurScene();
	MonScene->AddObj(pMBullet, ENUM_GAMEOBJ::BULLET);
}
