#pragma once

#include "Scene.h"  //UNKNOWN:인클루드 씬 헤더를 CPP에서 헤더로 옮겼더니, 씬매니저.cpp 초기화 영역의 new 부분이 잘 잡히고, 상속에서 불완전하다고 표시 된 public Scene이 해결된 이유 알아보기 

class SceneStart : public Scene //scene start 클래스에 scene 클래스를 상속합니다. scene class의 함수, 변수 사용가능
{
public:
	SceneStart();
	virtual ~SceneStart(); //가상함수로 선언
	virtual void Enter();
	virtual void Exit();
};

