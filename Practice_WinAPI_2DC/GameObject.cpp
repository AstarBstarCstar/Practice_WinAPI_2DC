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
}

void GameObject::Render(HDC hDC)
{
	Rectangle(hDC,
		m_fptPos.x - m_fptScale.x / 2,
		m_fptPos.y - m_fptScale.y / 2,
		m_fptPos.x + m_fptScale.x / 2,
		m_fptPos.y + m_fptScale.y / 2);
}