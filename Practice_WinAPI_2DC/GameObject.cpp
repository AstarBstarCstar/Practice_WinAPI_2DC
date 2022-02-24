#include "framework.h"
#include "GameObject.h"

/*UNKNOWN: ���� using namespace std ���� �Ϸ��� ��� �ϴ��� �ñ��ϴ�*/
GameObject::GameObject()
{
}

/*���ӿ�����Ʈ�� �����ǰ� �������� �������ִ� �ڵ� �Դϴ�*/
GameObject::GameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
}
GameObject::~GameObject()
{
}

/*�������� �缳�����ݴϴ�.*/
void GameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

/*�������� �缳�����ݴϴ�*/
void GameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

/*������ ���� ��ȯ�մϴ�.*/
fPoint GameObject::GetPos()
{
	return m_fptPos;
}

/*������ ���� ��ȯ�մϴ�.*/
fPoint GameObject::GetScale()
{
	return m_fptScale;
}

void GameObject::Update()
{
	/*UNKNOWN:pos�� m_fptpos�� �ٲ�� �ϴ� ���� �˾ƺ���*/
	if (KeyManager::GetInst()->GetButton(VK_LEFT))
	{
		m_fptPos.x -= 500 * TimeManager::GetInst()->GetDT();
	}

	if (KeyManager::GetInst()->GetButton(VK_RIGHT))
	{
		m_fptPos.x += 500 * TimeManager::GetInst()->GetDT();
	}

	if (KeyManager::GetInst()->GetButton(VK_UP))
	{
		m_fptPos.y -= 500 * TimeManager::GetInst()->GetDT();
	}

	if (KeyManager::GetInst()->GetButton(VK_DOWN))
	{
		m_fptPos.y += 500 * TimeManager::GetInst()->GetDT();
	}
}

void GameObject::Render(HDC hDC)
{
	Rectangle(hDC,
		m_fptPos.x - m_fptScale.x / 2,
		m_fptPos.y - m_fptScale.y / 2,
		m_fptPos.x + m_fptScale.x / 2,
		m_fptPos.y + m_fptScale.y / 2);
}
