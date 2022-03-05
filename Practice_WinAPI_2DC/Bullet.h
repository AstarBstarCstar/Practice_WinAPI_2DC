#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
private:
	float			m_fTheta;//총알의 방향 각도
	fPoint		m_Dir;  //총알이 나아갈 방향

public:
	virtual void Update();
	virtual void Render(HDC _dc);


	void SetDir(float theta)//TODO:각도를 알려줘서 본인의 방향을 알려주게끔 변경할것
	{
		this->m_fTheta = theta;
	}

	void SetVec(fPoint vec)//TODO:각도를 알려줘서 본인의 방향을 알려주게끔 변경할것
	{
		m_Dir = vec;
	}


public:
	Bullet();
	~Bullet();
};

