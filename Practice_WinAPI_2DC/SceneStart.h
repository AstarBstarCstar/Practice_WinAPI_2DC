#pragma once

#include "Scene.h"  //UNKNOWN:��Ŭ��� �� ����� CPP���� ����� �Ű����, ���Ŵ���.cpp �ʱ�ȭ ������ new �κ��� �� ������, ��ӿ��� �ҿ����ϴٰ� ǥ�� �� public Scene�� �ذ�� ���� �˾ƺ��� 

class SceneStart : public Scene //scene start Ŭ������ scene Ŭ������ ����մϴ�. scene class�� �Լ�, ���� ��밡��
{
public:
	SceneStart();
	virtual ~SceneStart(); //�����Լ��� ����
	virtual void Enter();
	virtual void Exit();
};

