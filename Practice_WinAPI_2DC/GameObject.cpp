#include "framework.h"
#include "GameObject.h"

/*UNKNOWN: 여기 using namespace std 없이 하려면 어떻게 하는지 궁굼하다*/
GameObject::GameObject()
{
}

/*게임오브젝트의 포지션과 스케일을 생성해주는 코드 입니다*/
GameObject::GameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
}
GameObject::~GameObject()
{
}

/*포지션을 재설정해줍니다.*/
void GameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

/*스케일을 재설정해줍니다*/
void GameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

/*포지션 값을 반환합니다.*/
fPoint GameObject::GetPos()
{
	return m_fptPos;
}

/*스케일 값을 반환합니다.*/
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