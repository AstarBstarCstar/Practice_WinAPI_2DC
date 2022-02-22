#include "CCore.h"
#include "framework.h"
//TODO:
CCore::CCore()
{
	m_hDC = 0;//���� ȭ�� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ ������
	//m_hMemDC = 0;
	//m_hBMP = 0;
}

CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

POINT g_rectPos;
/*������ ������ �Էµ� �������ֱ�*/
void CCore::update()
{
	TimeManager::getInst()->init();

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_rectPos.x -= 1 * TimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_rectPos.x += 1 * TimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		g_rectPos.y -= 1 * TimeManager::getInst()->GetDT();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		g_rectPos.y += 1 * TimeManager::getInst()->GetDT();
	}
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", TimeManager::getInst()->GetDT());
	TextOutW(m_hDC, WINSIZEX - 50, 10, m_uiFPS);
}

/*������ �׷��ִ� ����*/
void CCore::render()
{
	Rectangle(m_hMemDC,100, 100, 200, 200);//�׸��°� �޸� ��ÿ� ����
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
	
}

/*�ھ �ʱ�ȭ �ϴ� ����*/
void CCore::init()
{
	m_hDC = GetDC(hWnd);
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	g_rectPos.x = 300;
	g_rectPos.y = 300;
}