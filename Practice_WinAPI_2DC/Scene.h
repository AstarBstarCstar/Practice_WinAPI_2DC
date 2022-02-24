#pragma once

class GameObject; /*클래스의 전방선언*/

class Scene
{
private:
	vector<GameObject*> Arr_Obj[(int)ENUM_GAMEOBJ::SIZE]; //Arr_Obj라는 배열의 크기를 열거형 클래스의 사이즈로 정의합니다. (SIZE는 열거형의 맨 마지막)
	wstring StrName;//단순히 스트링 형태로 StrName 변수 정의입니다.

public:
	/*생성자와 소멸자 입니다*/
	Scene();
	virtual	~Scene();//가상함수 추가

	/*코어에 있던 업데이트와 렌더 함수를 Scene에 구현합니다.*/
	virtual void Update();
	virtual void Render(HDC hDC);
	
	virtual void Enter() = 0;//해당 함수는 해당 씬에 진입시 호출됩니다.
	virtual void Exit() = 0;//해당 함수는 해당 씬에서 탈출할 시 호출됩니다.

	void SetName(const wstring& name);
	wstring GetName();

	void AddObj(GameObject* PointObj, ENUM_GAMEOBJ type);
};


/*Tip:전방 선언 : 해당 클래스의 포인터 변수를 사용 할 수 있게 해준다.
1. 헤더파일이 여러번 호출되어 #pragma에 의해 선언부를 확인 불가한 문제를 해결한다.
2. 컴파일의 속도를 줄여준다.
씬 클래스에서는 게임 오브젝트 클래스를 전방선언 해준다.

마찬가지로 함수 전방선언 처럼 생각하면 될 것 같다.*/
