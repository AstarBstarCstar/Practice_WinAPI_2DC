#pragma once
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
};
