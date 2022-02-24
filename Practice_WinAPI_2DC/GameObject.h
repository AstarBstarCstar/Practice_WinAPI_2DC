#pragma once
class GameObject
{

private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	GameObject();
	GameObject(fPoint pos, fPoint scale);
  virtual	 ~GameObject();//�����Լ� �߰�

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();

	/*�ھ� Ŭ�������� �ߴ� ������ ������Ʈ�� ������ ������Ʈ Ŭ�������� �����մϴ�.*/
	void Update();
	void Render(HDC hDC);
};

