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
	fPoint CurPos = GetPos(); //���� ������Ʈ Ŭ����(�θ�Ŭ����) ���� ��ġ�� �޾ƿɴϴ�.

	CurPos.x += m_fSpeed * m_iDir * fDT;//��Ÿ x ���ǵ� x ���� (������ 1�̸� ������ -1�̸� �������� ���ϴ�)

	float f_Dist =  abs(m_fCenterPos.x - CurPos.x) - m_fMaxDis ;//�Ÿ����� üũ ���ݴϴ�. f_Dist�� �ʰ���

	if (0.f < f_Dist)//��ȸ�Ÿ��� �ִ��� �Ѿ �� ������ �ٲپ� �ݴϴ�. 
	{
		m_iDir *= (-1);
		CurPos.x += f_Dist * m_iDir;//���� �ʰ����� �� �������ִ� �Լ��Դϴ�.
	}
	SetPos(CurPos);								//����� ���� SetPos ���ݴϴ�.

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
	vShootBullet.y -= GetScale().y-150;//TODO:���� �Ѿ� �������� ����ϱ�, ������ ������ ����

	Bullet* pMBullet = new Bullet;
	pMBullet->SetPos(vShootBullet);
	pMBullet->SetScale(fPoint(10.f, 20.f));
	pMBullet->SetVec(fPoint(0, 1));

	Scene* MonScene = SceneManager::GetInst()->GetCurScene();
	MonScene->AddObj(pMBullet, ENUM_GAMEOBJ::BULLET);
}
