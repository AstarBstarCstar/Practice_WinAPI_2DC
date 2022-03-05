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
public:
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

	float Length()
	{
		return sqrt(x * x + y * y);//sqrt = 제곱근 함수
	}

	fPoint& Nomalize()//벡터의 정규화
	{
		float fLen = Length();
		assert(fLen != 0.f);

			x = x / fLen;
			y = y / fLen;
			x, y;
			return *this;
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
