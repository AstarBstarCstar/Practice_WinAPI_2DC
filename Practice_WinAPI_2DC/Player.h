#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	virtual void Update();//�θ��� ������Ʈ �Լ��� �����Լ��� ���� �������̵� �մϴ�.


	void CreateBullet();
};

