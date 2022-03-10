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
	/*AddObj를 직접 인덱스에 추가하는게 아니라, 함수를 통해 추가해주었다.*/
	AddObj(PointObj, ENUM_GAMEOBJ::PLAYER);


	/*여기에 오브젝트를 만들때: 나는 오브젝트 클래스를 객체 생성으로 만들 생각이 없었는데 객체화 되고 있다. 이유: 모든 오브젝트의 부모 파트이기 때문.
	따라서 오브젝트 클래스를 순수 가상함으로 만드는것을 진행한다.*/


	/*몬스터를 배치하는 코드입니다.*/
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
	//TODO:HELP 이걸 화면 밖으로 안나가게 범위를 설정하려면?




	//TODO: 몬스터 두마리 테스트로 추가
	//PointObj = new GameObject;
	//PointObj->SetPos(fPoint(1000.f, 500.f));
	//PointObj->SetScale(fPoint(200.f, 200.f));
	///*AddObj를 직접 인덱스에 추가하는게 아니라, 함수를 통해 추가해주었다.*/
	//AddObj(PointObj, ENUM_GAMEOBJ::DEFAULT);

	//PointObj = new GameObject;
	//PointObj->SetPos(fPoint(1000.f, 100.f));
	//PointObj->SetScale(fPoint(100.f, 100.f));
	///*AddObj를 직접 인덱스에 추가하는게 아니라, 함수를 통해 추가해주었다.*/
	//AddObj(PointObj, ENUM_GAMEOBJ::DEFAULT);
}

void SceneStart::Exit()
{
}
