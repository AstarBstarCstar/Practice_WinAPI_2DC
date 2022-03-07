#include "framework.h"
#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "Texture.h"

Player::Player()
{
	/*Texture �ε��ϱ�*/
	m_pTexture = new Texture;//<- �� ������ �ٷ� �̹��� ������ ��� ����
	wstring str_FilePath = PathManager::GetInst()->GetContentsPath();
	str_FilePath += L"texture\\pa.bmp";//��θ� �ҷ�����, �� bmp ������ �󼼰�θ� �Է�.
	m_pTexture->Load(str_FilePath);//���� �̹��� �Լ��� �ֱ�
}

Player::~Player()
{
	if (nullptr != m_pTexture)
		delete m_pTexture;
}
/*���� �÷��̾� ��ü�� �÷��̾��� ������Ʈ �Լ��� ȣ���մϴ�.(virtual)*/
void Player::Update()//�θ� �ִ� �����̴� �ڵ带 �÷��̾� Ŭ�������� �����մϴ�.
{
	fPoint m_fptPos = GetPos();//�������� �������� �ٽ� �� ������� ��
	
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

void Player::Render(HDC _dc)
{
	int iWidth = (int)m_pTexture->Width();
	int iHeight = (int)m_pTexture->Heigh();
	fPoint Pos = GetPos();

	BitBlt(_dc, Pos.x - int((float)(iWidth / 2)), int(Pos.y - (float)(iHeight / 2)), iWidth, iHeight, m_pTexture->GetDC(), 0, 0, SRCCOPY);
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

