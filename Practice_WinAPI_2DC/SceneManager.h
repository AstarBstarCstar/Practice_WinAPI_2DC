#pragma once

class Scene;//Scene 클래스를 전방선언 합니다.

class SceneManager
{
	SINGLETON(SceneManager);

private:
	Scene* Arr_Scene[(int)ENUM_SCENE::SIZE];//열거형 클래스의 사이즈 만큼을 ArrScene의 배열갯수로 선언하며 이 배열은 포인터형 입니다. (int를 붙인 이유는 열거형 클래스이기 때문)
	Scene* CurScene;
	
public:
	void Update();
	void Render(HDC hDC);
	void Init();

public:
	Scene* GetCurScene() { return CurScene; }
};

