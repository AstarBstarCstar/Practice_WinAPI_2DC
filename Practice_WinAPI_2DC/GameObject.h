#pragma once
/*오브젝트 클래스는 앞으로 파생될 모든 다양한 종류의 오브젝트의 부모격 클래스이다*/
class GameObject
{

private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	GameObject();
	GameObject(fPoint pos, fPoint scale);
  virtual	 ~GameObject();//가상함수 추가

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	/*코어 클래스에서 했던 렌더와 업데이트는 앞으로 오브젝트 클래스에서 실행합니다.*/
	/*오브젝트 클래스를 추상클래스로 만들어주었습니다. 순수가상함수 사용*/
	/*오브젝트 클래스의 업데이트와 렌더가 버*/
	virtual void Update()=0;//업데이트와 렌더는 클래스마다 꼭 구현을 하기 위해 순수 가상함수로 만들었다.
	virtual void Render(HDC hDC);
};

