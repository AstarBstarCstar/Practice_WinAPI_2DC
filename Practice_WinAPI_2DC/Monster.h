#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
private:
	float		m_fSpeed; 
	float		m_fMaxDis;
	fPoint    m_fCenterPos;
	int			m_iDir; //우측이면 양수 좌측이면 음수
	Texture* m_pMonTexture;


public:
	Monster();
	~Monster();


	float GetSpeed() { return m_fSpeed; }
	void SetSpeed(float speed) { this->m_fSpeed = speed; }

	void SetCenterPos(fPoint pos) { this->m_fCenterPos = pos; }
	void ShootBullet();


	virtual void Update();
	virtual void Render(HDC _dc);
};

