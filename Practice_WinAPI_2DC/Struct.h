#pragma once
#include <assert.h>
/*좌표를 위한 단순 스트럭트 헤더파일 입니다*/
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
	/*:::연산자 재정의부:::*/
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
