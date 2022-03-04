#include "framework.h"
#include "Scene.h"
#include "GameObject.h"
/*����� ����������, framework.h ���� GameObject.h�� �����Ƿ� GameObject.h�� ���� �������ݴϴ�.*/


/*Scene�� �����ڿ� �Ҹ��ڸ� �����մϴ�.*/
Scene:: Scene()
{
	StrName = L"";
}
Scene::~Scene()// ���߹迭ó�� ����� �����迭+���͸� �����ִ� �ڵ��Դϴ�.
{
	for (int i = 0; i < (int)ENUM_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < Arr_Obj[i].size(); j++)
		{
			delete Arr_Obj[i][j];
		}
	}
}

void Scene::Update()/*��� �迭,���͸� ���鼭 ������Ʈ ���ִ� �Լ��Դϴ�. */
{
	for (int i = 0; i < ((int)ENUM_GAMEOBJ::SIZE); i++)
	{
		for (int j = 0; j < Arr_Obj[i].size(); j++)
		{
			Arr_Obj[i][j]->Update();
		}
	}
}

void Scene::Render(HDC hDC)/* ��� �迭, ���͸� ���鼭 ���� ���ִ� �Լ��Դϴ�.*/
{
	for (int i = 0; i < ((int)ENUM_GAMEOBJ::SIZE); i++)
	{
		for (int j = 0; j < Arr_Obj[i].size(); j++)
		{
			Arr_Obj[i][j]->Render(hDC);
		}
	}
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
