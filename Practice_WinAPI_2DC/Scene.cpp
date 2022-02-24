#include "framework.h"
#include "Scene.h"
#include "GameObject.h"
/*헤더를 선언하지만, framework.h 내에 GameObject.h가 없으므로 GameObject.h도 같이 선언해줍니다.*/


/*Scene의 생성자와 소멸자를 정의합니다.*/
Scene:: Scene()
{
	StrName = L"";
}
Scene::~Scene()
{
}

void Scene::SetName(const wstring& name)//wstring의 name 의 '번지값을' StrName에 넣어줍니다.
{
	StrName = name;
}

wstring Scene::GetName()//StrName을 반환해주는 함수입니다.
{
	return StrName;
}

/*오브젝트를 배열,벡터공간에 저장하는 함수이며, 게임오브젝트의 포인터형 지역변수와, 열거형클래스 지역변수를 사용합니다.*/
void Scene::AddObj(GameObject* PointObj, ENUM_GAMEOBJ type)//해당 변수는 고정배열 안에 벡터를 또 선언하여 2차원 배열처럼 사용합니다.
{								
	Arr_Obj[(int)type].push_back(PointObj);
}
