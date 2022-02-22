#pragma once
class GameObject
{
private:
	fPoint b_Pos;
	fPoint b_Scale;
public:
	GameObject();
	GameObject(fPoint pos, fPoint scale);
	~GameObject();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();
};

