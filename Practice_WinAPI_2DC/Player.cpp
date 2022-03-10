#include "framework.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "Texture.h"
#include "Sound.h"

Player::Player()
{
	/*Texture 로딩하기*/
	m_pTexture = ResourceManager::GetInst()->LoadTexture(L"PlayerTexture", L"texture\\pa.bmp");
	//wstring str_FilePath = PathManager::GetInst()->GetContentsPath();
	//str_FilePath += L"texture\\pa.bmp";//경로를 불러오고, 쓸 bmp 파일의 상세경로를 입력.
	//m_pTexture->Load(str_FilePath);//만든 이미지 함수에 넣기
}

Player::~Player()
{
	//if (nullptr != m_pTexture)
	//	delete m_pTexture;
}
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
	if (KEY_STATE GetButtonDown(VK_CONTROL))
	{
		Sound* pSound = new Sound;
		pSound->Load(L"contents\\sound\\Maple2Boss4.wav");
		pSound->Play();
	}
	SetPos(m_fptPos);
}

void Player::Render(HDC _dc)
{
	int iWidth = (int)m_pTexture->Width();
	int iHeight = (int)m_pTexture->Heigh();
	fPoint Pos = GetPos();

	/*BitBlt(_dc, Pos.x - int((float)(iWidth / 2)), int(Pos.y - (float)(iHeight / 2)), iWidth, iHeight, m_pTexture->GetDC(), 0, 0, SRCCOPY);*/
	/*트랜스패렌트블릿을 사용하기 위해선 Msimg32.lib을 참조해야 함(선언은 가능하지만 없다면 실사용은 불가능)*/
	TransparentBlt(_dc, Pos.x - int((float)(iWidth / 2)), int(Pos.y - (float)(iHeight / 2)), iWidth, iHeight, m_pTexture->GetDC(),0,0, iWidth, iHeight, RGB(255,0,255));//특정 조건의 색상을 걷어내서 그려주는 함수 위의 비트블릿 함수와 호출조건이 거의 비슷하다 볼 수 있음.
}

void Player::CreateBullet()
{
	fPoint vBulletPos = GetPos();
	vBulletPos.y -= GetScale().y / 2.f;

	Bullet* pBullet = new Bullet;
	pBullet->SetPos(vBulletPos);
	pBullet->SetScale(fPoint(10.f, 20.f));
	pBullet->SetVec(fPoint(0, -1));

	Scene* CurScene =SceneManager::GetInst()->GetCurScene();
	CurScene->AddObj(pBullet,ENUM_GAMEOBJ::BULLET);
}

