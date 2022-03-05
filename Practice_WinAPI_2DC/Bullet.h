#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
private:
	float			m_fTheta;//�Ѿ��� ���� ����
	fPoint		m_Dir;  //�Ѿ��� ���ư� ����

public:
	virtual void Update();
	virtual void Render(HDC _dc);


	void SetDir(float theta)//TODO:������ �˷��༭ ������ ������ �˷��ְԲ� �����Ұ�
	{
		this->m_fTheta = theta;
	}

	void SetVec(fPoint vec)//TODO:������ �˷��༭ ������ ������ �˷��ְԲ� �����Ұ�
	{
		m_Dir = vec;
	}


public:
	Bullet();
	~Bullet();
};

