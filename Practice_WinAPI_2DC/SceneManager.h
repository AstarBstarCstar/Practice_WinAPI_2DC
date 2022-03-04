#pragma once

class Scene;//Scene Ŭ������ ���漱�� �մϴ�.

class SceneManager
{
	SINGLETON(SceneManager);

private:
	Scene* Arr_Scene[(int)ENUM_SCENE::SIZE];//������ Ŭ������ ������ ��ŭ�� ArrScene�� �迭������ �����ϸ� �� �迭�� �������� �Դϴ�. (int�� ���� ������ ������ Ŭ�����̱� ����)
	Scene* CurScene;
	
public:
	void Update();
	void Render(HDC hDC);
	void Init();

public:
	Scene* GetCurScene() { return CurScene; }
};

