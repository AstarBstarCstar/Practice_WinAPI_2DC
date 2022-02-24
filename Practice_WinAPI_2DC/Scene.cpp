#include "framework.h"
#include "Scene.h"
#include "GameObject.h"
/*����� ����������, framework.h ���� GameObject.h�� �����Ƿ� GameObject.h�� ���� �������ݴϴ�.*/


/*Scene�� �����ڿ� �Ҹ��ڸ� �����մϴ�.*/
Scene:: Scene()
{
	StrName = L"";
}
Scene::~Scene()
{
}

void Scene::SetName(const wstring& name)//wstring�� name �� '��������' StrName�� �־��ݴϴ�.
{
	StrName = name;
}

wstring Scene::GetName()//StrName�� ��ȯ���ִ� �Լ��Դϴ�.
{
	return StrName;
}

/*������Ʈ�� �迭,���Ͱ����� �����ϴ� �Լ��̸�, ���ӿ�����Ʈ�� �������� ����������, ������Ŭ���� ���������� ����մϴ�.*/
void Scene::AddObj(GameObject* PointObj, ENUM_GAMEOBJ type)//�ش� ������ �����迭 �ȿ� ���͸� �� �����Ͽ� 2���� �迭ó�� ����մϴ�.
{								
	Arr_Obj[(int)type].push_back(PointObj);
}
