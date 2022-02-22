#pragma once
/*코어클래스는 두개가 존재하면 안됨 게임의 관리자는 단 하나만
게임의 관리자가 두개면 두가지 게임을 굴리는것과 마찬가지 (단 하나만 하기 위해선 싱글톤으로 구현)
EX) CCore a,CCore b 같은 것은 하면 안되므로 생성자를 프라이빗으로 선언 하여 외부에서 못만들게 할 것*/
class CCore
{
	SINGLETON(CCore);

private:
	HDC			m_hDC;		//윈도우 DC
	HDC			m_hMemDC;	//메모리 DC
	HBITMAP		m_hBMP;		//메모리 비트맵

public:
	void Update();/*게임 상황 입력 출력 등등 계속 업데이트 */
	void Render();/*게임 상황 계속 그려주는 부분*/
	void Init();/*초기화 과정*/
};

