#include "GameObject.h"
#include "framework.h"

/*TODO: ���� using namespace std ���� �Ϸ��� ��� �ϴ��� �ñ��ϴ�*/
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