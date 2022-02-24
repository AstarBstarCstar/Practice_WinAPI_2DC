#include "framework.h"
#include "SceneStart.h"
#include "GameObject.h"

SceneStart::SceneStart()
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Enter()
{
	GameObject* PointObj = new GameObject;

	PointObj->SetPos(fPoint(100, 100));
	PointObj->SetScale(fPoint(300, 300));
	
	AddObj(PointObj, ENUM_GAMEOBJ::DEFAULT);//UNKNOWN: �̰� ���� ������ �𸣰��� �˾ƺ���
}

void SceneStart::Exit()
{
}
