#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
private:
	float			m_fDir;//ÃÑ¾ËÀÇ ¹æÇâ


public:
	virtual void Update();
	virtual void Render(HDC _dc);


	void SetDir(bool Dir)
	{
		if (Dir)
			this->m_fDir = -1.f;

		else
			this->m_fDir = 1.f;
	}


public:
	Bullet();
	~Bullet();
};

