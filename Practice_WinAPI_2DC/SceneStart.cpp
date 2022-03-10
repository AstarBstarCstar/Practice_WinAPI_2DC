#include "framework.h"
#include "SceneStart.h"
#include "GameObject.h"
#include "Sound.h"
#include "Player.h"
#include "Monster.h"


SceneStart::SceneStart()
{
}

SceneStart::~SceneStart()
{
}

void SceneStart::Enter()
{
	

	GameObject* PointObj = new Player;
	PointObj->SetPos(fPoint(100.f, 100.f));
	PointObj->SetScale(fPoint(50.f, 50.f));
	/*AddObj�� ���� �ε����� �߰��ϴ°� �ƴ϶�, �Լ��� ���� �߰����־���.*/
	AddObj(PointObj, ENUM_GAMEOBJ::PLAYER);


	/*���⿡ ������Ʈ�� ���鶧: ���� ������Ʈ Ŭ������ ��ü �������� ���� ������ �����µ� ��üȭ �ǰ� �ִ�. ����: ��� ������Ʈ�� �θ� ��Ʈ�̱� ����.
	���� ������Ʈ Ŭ������ ���� ���������� ����°��� �����Ѵ�.*/


	/*���͸� ��ġ�ϴ� �ڵ��Դϴ�.*/
	fPoint fResolution;
	fResolution.x = WINSIZEX;
	float Term = (fResolution.x - (10.f * 2)) / 4.f;

	Monster* pMonsterObj = nullptr;
	for (int i = 0; i < 6; ++i)
	{
		Monster* pMonsterObj = new Monster;
		pMonsterObj->SetPos(fPoint(10.f + (float)i* Term,50.f));
		pMonsterObj->SetCenterPos(fPoint(pMonsterObj->GetPos()));
		pMonsterObj->SetScale(fPoint(50.f, 100.f));
		AddObj(pMonsterObj, ENUM_GAMEOBJ::MONSTER);
	}
	//TODO:HELP �̰� ȭ�� ������ �ȳ����� ������ �����Ϸ���?




	//TODO: ���� �θ��� �׽�Ʈ�� �߰�
	//PointObj = new GameObject;
	//PointObj->SetPos(fPoint(1000.f, 500.f));
	//PointObj->SetScale(fPoint(200.f, 200.f));
	///*AddObj�� ���� �ε����� �߰��ϴ°� �ƴ϶�, �Լ��� ���� �߰����־���.*/
	//AddObj(PointObj, ENUM_GAMEOBJ::DEFAULT);

	//PointObj = new GameObject;
	//PointObj->SetPos(fPoint(1000.f, 100.f));
	//PointObj->SetScale(fPoint(100.f, 100.f));
	///*AddObj�� ���� �ε����� �߰��ϴ°� �ƴ϶�, �Լ��� ���� �߰����־���.*/
	//AddObj(PointObj, ENUM_GAMEOBJ::DEFAULT);
}

void SceneStart::Exit()
{
}
