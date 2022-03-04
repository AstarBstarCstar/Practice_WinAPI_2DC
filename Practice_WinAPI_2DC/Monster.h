#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
private:
	float		m_fSpeed; 
	float		m_fMaxDis;
	fPoint    m_fCenterPos;
	int			m_iDir; //�����̸� ��� �����̸� ����


public:
	Monster();
	~Monster();


	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float speed) { this->m_fSpeed = speed; }

	void SetCenterPos(fPoint pos) { this->m_fCenterPos = pos; }


	virtual void Update();
};

