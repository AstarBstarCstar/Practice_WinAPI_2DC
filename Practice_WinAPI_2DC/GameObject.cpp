#include "framework.h"
#include "GameObject.h"

/*UNKNOWN: 여기 using namespace std 없이 하려면 어떻게 하는지 궁굼하다*/
GameObject::GameObject()
{
}
GameObject::GameObject(fPoint pos, fPoint scale)
{
	m_fptPos = pos;
	m_fptScale = scale;
}
GameObject::~GameObject()
{
}

void GameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void GameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint GameObject::GetPos()
{
	return m_fptPos;
}

fPoint GameObject::GetScale()
{
	return m_fptScale;
}