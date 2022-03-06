#pragma once
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
	HDC GetMainDC() { return m_hDC; }

	//HWND GetMainHwnd() { return m_hWnd; }  //TODO:hWnd를 리턴하는 함수 제작
	//POINT GetResolution() { return m_ptResolution; } //TODO:해상도를 리턴하는 함수 제작
};

