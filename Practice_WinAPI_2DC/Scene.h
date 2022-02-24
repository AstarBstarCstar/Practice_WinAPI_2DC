#pragma once

class GameObject; /*Ŭ������ ���漱��*/

class Scene
{
private:
	vector<GameObject*> Arr_Obj[(int)ENUM_GAMEOBJ::SIZE]; //Arr_Obj��� �迭�� ũ�⸦ ������ Ŭ������ ������� �����մϴ�. (SIZE�� �������� �� ������)
	wstring StrName;//�ܼ��� ��Ʈ�� ���·� StrName ���� �����Դϴ�.

public:
	/*�����ڿ� �Ҹ��� �Դϴ�*/
	Scene();
	virtual	~Scene();//�����Լ� �߰�

	/*�ھ �ִ� ������Ʈ�� ���� �Լ��� Scene�� �����մϴ�.*/
	virtual void Update();
	virtual void Render(HDC hDC);
	
	virtual void Enter() = 0;//�ش� �Լ��� �ش� ���� ���Խ� ȣ��˴ϴ�.
	virtual void Exit() = 0;//�ش� �Լ��� �ش� ������ Ż���� �� ȣ��˴ϴ�.

	void SetName(const wstring& name);
	wstring GetName();

	void AddObj(GameObject* PointObj, ENUM_GAMEOBJ type);
};


/*Tip:���� ���� : �ش� Ŭ������ ������ ������ ��� �� �� �ְ� ���ش�.
1. ��������� ������ ȣ��Ǿ� #pragma�� ���� ����θ� Ȯ�� �Ұ��� ������ �ذ��Ѵ�.
2. �������� �ӵ��� �ٿ��ش�.
�� Ŭ���������� ���� ������Ʈ Ŭ������ ���漱�� ���ش�.

���������� �Լ� ���漱�� ó�� �����ϸ� �� �� ����.*/
