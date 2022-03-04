#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
private:
	float		m_fSpeed; 
	float		m_fMaxDis;
	fPoint    m_fCenterPos;
	int			m_iDir; //우측이면 양수 좌측이면 음수


public:
	Monster();
	~Monster();


	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float speed) { this->m_fSpeed = speed; }

	void SetCenterPos(fPoint pos) { this->m_fCenterPos = pos; }


	virtual void Update();
};

