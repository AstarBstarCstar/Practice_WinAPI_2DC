#pragma once
class CCore
{
	SINGLETON(CCore);

private:
	HDC			m_hDC;		//������ DC
	HDC			m_hMemDC;	//�޸� DC
	HBITMAP		m_hBMP;		//�޸� ��Ʈ��

public:
	void Update();/*���� ��Ȳ �Է� ��� ��� ��� ������Ʈ */
	void Render();/*���� ��Ȳ ��� �׷��ִ� �κ�*/
	void Init();/*�ʱ�ȭ ����*/
	HDC GetMainDC() { return m_hDC; }

	//HWND GetMainHwnd() { return m_hWnd; }  //TODO:hWnd�� �����ϴ� �Լ� ����
	//POINT GetResolution() { return m_ptResolution; } //TODO:�ػ󵵸� �����ϴ� �Լ� ����
};

