#pragma once
class TimeManager
{
	SINGLETON(TimeManager);

private:
	/*LARGE_INTEGER은 long long 변수의 공용체 HighPart + LowPart = QuadPart 입니다.*/
	LARGE_INTEGER	m_llCurCount;  /*현재 카운트*/
	LARGE_INTEGER   m_llPrevCount; /*이전 카운트*/
	LARGE_INTEGER   m_llFreq;      /*초당 카운트 횟수*/

	unsigned int	m_uiFPS; //FPS : 1초당 그려진 화면 수
	double			m_dDT; // Delta Time : 1프레임당 소요된 시간

public:
	void		 Update();  /*한 업데이트당 fps,dt*/
	void		 Init();	/*timemanager 초기화시키기*/

	unsigned int GetFPS();//FPS값을 반환합니다.
	double		 GetDT();//DT값을 반환합니다.
};

