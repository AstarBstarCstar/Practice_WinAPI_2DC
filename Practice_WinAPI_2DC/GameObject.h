#pragma once
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
	void Update();
	void Render(HDC hDC);
};

