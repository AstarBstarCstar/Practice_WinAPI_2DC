#pragma once
#include "GameObject.h"

class Texture;

class Player : public GameObject
{
private:
	Texture* m_pTexture;
public:
	virtual void Update();//부모의 업데이트 함수를 가상함수를 통해 오버라이딩 합니다.
	virtual void Render(HDC _dc);//부모의 렌더 함수를 가상함수를 통해 오버라이딩 하여 텍스쳐 파일을 그립니다.
private:
	void CreateBullet();

public:
	Player();
	~Player();
};

