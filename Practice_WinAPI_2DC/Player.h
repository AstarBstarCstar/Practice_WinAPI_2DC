#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	virtual void Update();//부모의 업데이트 함수를 가상함수를 통해 오버라이딩 합니다.


	void CreateBullet();
};

