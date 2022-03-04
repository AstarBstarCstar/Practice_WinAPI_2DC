#pragma once
/*������Ʈ Ŭ������ ������ �Ļ��� ��� �پ��� ������ ������Ʈ�� �θ�� Ŭ�����̴�*/
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
	/*������Ʈ Ŭ������ �߻�Ŭ������ ������־����ϴ�. ���������Լ� ���*/
	/*������Ʈ Ŭ������ ������Ʈ�� ������ ��*/
	virtual void Update()=0;//������Ʈ�� ������ Ŭ�������� �� ������ �ϱ� ���� ���� �����Լ��� �������.
	virtual void Render(HDC hDC);
};

