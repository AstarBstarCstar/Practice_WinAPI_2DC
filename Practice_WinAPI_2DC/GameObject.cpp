#include "GameObject.h"
#include "framework.h"

/*TODO: 여기 using namespace std 없이 하려면 어떻게 하는지 궁굼하다*/
GameObject::GameObject()
{
}
GameObject::GameObject(fPoint pos, fPoint scale)
{
	b_Pos = pos;
	b_Scale = scale;
}
GameObject::~GameObject()
{
}

void GameObject::SetPos(fPoint pos)
{
	b_Pos = pos;
}

void GameObject::SetScale(fPoint scale)
{
	b_Scale = scale;
}

fPoint GameObject::GetPos()
{
	return b_Pos;
}

fPoint GameObject::GetScale()
{
	return b_Scale;
}