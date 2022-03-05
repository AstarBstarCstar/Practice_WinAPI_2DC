#pragma once
#include <assert.h>
/*��ǥ�� ���� �ܼ� ��Ʈ��Ʈ ������� �Դϴ�*/
struct iPoint
{
	int x;
	int y;
};

struct fPoint
{
	float x;
	float y;
	fPoint()
	{
		x = 0;
		y = 0;
	}
	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	/*:::������ �����Ǻ�:::*/
	fPoint& operator=(const fPoint& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	fPoint operator+(const fPoint& other)
	{
		return fPoint(x + other.x, y + other.y);
	}
	fPoint operator-(const fPoint& other)
	{
		return fPoint(x - other.x, y - other.y);
	}
	
	template<typename T>
	fPoint operator *(T num)
	{
		return fPoint(x * num, y * num);
	}
	template<typename T>
	fPoint operator /(T num)
	{
		assert(num == 0);
		return fPoint(x / num, y / num);
	}
	


};
