#include "framework.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"

/*이제 플레이어 객체는 플레이어의 업데이트 함수를 호출합니다.(virtual)*/
void Player::Update()//부모에 있던 움직이는 코드를 플레이어 클래스에서 진행합니다.
{
	fPoint m_fptPos = GetPos();//지역변수 변경점을 다시 셋 시켜줘야 함
	
	if (KEY_STATE GetButton(VK_LEFT))
	{
		m_fptPos.x -= 500 * fDT
	}
	if (KEY_STATE GetButton(VK_RIGHT))
	{
		m_fptPos.x += 500 * fDT
	}
	if (KEY_STATE GetButton(VK_UP))
	{
		m_fptPos.y -= 500 * fDT
	}
	if (KEY_STATE GetButton(VK_DOWN))
	{
		m_fptPos.y += 500 * fDT
	}
	if (KEY_STATE GetButton(VK_SHIFT))
	{
		CreateBullet();
	}
	SetPos(m_fptPos);
}

void Player::CreateBullet()
{
	fPoint vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;//TODO:몬스터 총알 랜덤으로 쏘게하기, 연산자 재정의 시전

	Bullet* pBullet = new Bullet;
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(fPoint(10.f, 20.f));
	pBullet->SetVec(fPoint(0, -1));

	Scene* CurScene =SceneManager::GetInst()->GetCurScene();
	CurScene->AddObj(pBullet,ENUM_GAMEOBJ::BULLET);
}
