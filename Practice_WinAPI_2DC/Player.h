#pragma once
#include "GameObject.h"

class Texture;

class Player : public GameObject
{
private:
	Texture* m_pTexture;
public:
	virtual void Update();//�θ��� ������Ʈ �Լ��� �����Լ��� ���� �������̵� �մϴ�.
	virtual void Render(HDC _dc);//�θ��� ���� �Լ��� �����Լ��� ���� �������̵� �Ͽ� �ؽ��� ������ �׸��ϴ�.
private:
	void CreateBullet();

public:
	Player();
	~Player();
};

