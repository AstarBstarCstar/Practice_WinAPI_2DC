#include "framework.h"
#include "SceneManager.h"
#include "SceneStart.h"

SceneManager::SceneManager()//�� �Ŵ����� �������� �迭��, ���� ���� ���� nullptr�� �ʱ�ȭ �����ݴϴ�.
{
	for (int i = 0; i < ((int)ENUM_SCENE::SIZE); i++)
	{
		Arr_Scene[i] = nullptr;
	}
	CurScene = nullptr;
}

SceneManager::~SceneManager()//���� �迭�� ����ִٸ� �Ҵ��� �������ִ� �Ҹ��� �Դϴ�.
{
	for (int i = 0; i < ((int)ENUM_SCENE::SIZE); i++)
	{
		if (nullptr != Arr_Scene[i])
		{
			delete Arr_Scene[i];
		}
	}
}

void SceneManager::Update()
{
	CurScene->Update();
}

void SceneManager::Render(HDC hDC)
{
	CurScene->Render(hDC);
}

void SceneManager::Init()//SceneManager �� �ʱ�ȭ �����ִ� �Լ��Դϴ�.
{
	Arr_Scene[(size_t)ENUM_SCENE::START] = new SceneStart;//UNKNOWN: Scene_start.cpp�� ���� ������Ʈ ��� �߰��ϴ� scenestart ���� ����� ���� �˾ƺ���.
	Arr_Scene[(size_t)ENUM_SCENE::START]->SetName(L"Start_Scene");

	CurScene = Arr_Scene[(size_t)ENUM_SCENE::START];
	CurScene->Enter();
}