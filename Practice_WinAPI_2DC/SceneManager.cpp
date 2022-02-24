#include "framework.h"
#include "SceneManager.h"
#include "SceneStart.h"

SceneManager::SceneManager()//씬 매니저의 포인터형 배열과, 현재 씬을 전부 nullptr로 초기화 시켜줍니다.
{
	for (int i = 0; i < ((int)ENUM_SCENE::SIZE); i++)
	{
		Arr_Scene[i] = nullptr;
	}
	CurScene = nullptr;
}

SceneManager::~SceneManager()//씬의 배열이 비어있다면 할당을 해제해주는 소멸자 입니다.
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

void SceneManager::Init()//SceneManager 을 초기화 시켜주는 함수입니다.
{
	Arr_Scene[(size_t)ENUM_SCENE::START] = new SceneStart;//UNKNOWN: Scene_start.cpp에 게임 오브젝트 헤더 추가하니 scenestart 밑줄 사라진 이유 알아보기.
	Arr_Scene[(size_t)ENUM_SCENE::START]->SetName(L"Start_Scene");

	CurScene = Arr_Scene[(size_t)ENUM_SCENE::START];
	CurScene->Enter();
}