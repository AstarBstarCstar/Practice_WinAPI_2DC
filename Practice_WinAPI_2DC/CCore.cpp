#include "framework.h"
#include "CCore.h"

CCore::CCore()
{
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
}

/*게임 코어 종료 시점에 DC 핸들값 반납 소멸자영역입니다*/
CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

/*게임의 정보들 입력등 갱신해주는 영역입니다*/
void CCore::Update()
{
	KeyManager::GetInst()->Update();
	TimeManager::GetInst()->Update();
	SceneManager::GetInst()->Update();
	/*UIManager::GetInst->Update();*/
}

/*게임을 그려주는 영역입니다*/
void CCore::Render()
{
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	SceneManager::GetInst()->Render(m_hMemDC);

	/*오른쪽 상단에 프레임을 표시하는 코드입니다*/
	WCHAR strFPS[6];

	swprintf_s(strFPS, L"%5d", TimeManager::GetInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

/*코어를 초기화 하는 영역입니다.*/
void CCore::Init()
{
	PathManager::GetInst()->Init();
	TimeManager::GetInst()->Init();
	KeyManager::GetInst()->Init();
	SceneManager::GetInst()->Init();
	

	m_hDC = GetDC(hWnd);

	/*더블 버퍼링의 메모리 DC와 메모리 비트맵을 생성하는 코드입니다*/
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}















//void CCore::Update()
//{
//	KeyManager::GetInst()->Update();
//	TimeManager::GetInst()->Update();
//
//	//UNKNOWN: 프레임 워크 extern 수정하니 갑자기 안되던게 잘 됨 이유 알아보기
//
//	//fPoint pos = Obj.GetPos();
//	///*GetAsuncKeyState: 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인하는 함수입니다.*/
//	//if (KeyManager::GetInst()->GetButton(VK_LEFT))
//	//{/*SOLVED:사각형 이상하게 움직이는 건에 대해서 타임 함수는 문제가 없음(확인)*/
//	//	pos.x -= 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_RIGHT))
//	//{
//	//	pos.x += 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_UP))
//	//{
//	//	pos.y -= 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_DOWN))
//	//{
//	//	pos.y += 5000 * TimeManager::GetInst()->GetDT();
//	//}
//	//Obj.SetPos(pos);
//	/*ㄴ게임을 그려주거나 위치좌표 등은 오브젝트 클래스로 이동합니다*/
//
//	SceneManager::GetInst()->Update();//이동후 이 함수들을 추가합니다.
//}
//
///*게임을 그려주는 영역입니다*/
//void CCore::Render()
//{
//	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
//
//	//Rectangle(m_hMemDC,
//	//	Obj.GetPos().x - Obj.GetScale().x / 2,
//	//	Obj.GetPos().y - Obj.GetScale().y / 2,
//	//	Obj.GetPos().x + Obj.GetScale().x / 2,
//	//	Obj.GetPos().y + Obj.GetScale().y / 2);
//
//	//Rectangle(m_hMemDC,
//	//	Obj.GetPos().x - Obj.GetScale().x / 2 + 200,
//	//	Obj.GetPos().y - Obj.GetScale().y / 2,
//	//	Obj.GetPos().x + Obj.GetScale().x / 2 + 200,
//	//	Obj.GetPos().y + Obj.GetScale().y / 2);
//
//	//Rectangle(m_hMemDC,
//	//	Obj.GetPos().x - Obj.GetScale().x / 2,
//	//	Obj.GetPos().y - Obj.GetScale().y / 2 + 200,
//	//	Obj.GetPos().x + Obj.GetScale().x / 2,
//	//	Obj.GetPos().y + Obj.GetScale().y / 2 + 200);
//
//	//Rectangle(m_hMemDC,
//	//	Obj.GetPos().x - Obj.GetScale().x / 2 + 200,
//	//	Obj.GetPos().y - Obj.GetScale().y / 2 + 200,
//	//	Obj.GetPos().x + Obj.GetScale().x / 2 + 200,
//	//	Obj.GetPos().y + Obj.GetScale().y / 2 + 200);
//	/*ㄴ게임을 그려주거나 위치좌표 등은 오브젝트 클래스로 이동합니다*/
//
//	SceneManager::GetInst()->Render(m_hMemDC);//클래스로 이동 후 이 함수를 추가합니다.
//
//	/*오른쪽 상단에 프레임을 표시하는 코드입니다*/
//	WCHAR strFPS[6];
//
//	swprintf_s(strFPS, L"%5d", TimeManager::GetInst()->GetFPS());
//	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);
//
//	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
//}
//
//void CCore::Update()
//{
//	KeyManager::GetInst()->Update();
//	TimeManager::GetInst()->Update();
//
//	//UNKNOWN: 프레임 워크 extern 수정하니 갑자기 안되던게 잘 됨 이유 알아보기
//
//	//fPoint pos = Obj.GetPos();
//	///*GetAsuncKeyState: 메시지 큐에 키 입력을 받는 방식이 아닌 현재 상태의 키 입력상태를 확인하는 함수입니다.*/
//	//if (KeyManager::GetInst()->GetButton(VK_LEFT))
//	//{/*SOLVED:사각형 이상하게 움직이는 건에 대해서 타임 함수는 문제가 없음(확인)*/
//	//	pos.x -= 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_RIGHT))
//	//{
//	//	pos.x += 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_UP))
//	//{
//	//	pos.y -= 5000 * TimeManager::GetInst()->GetDT();
//	//}
//
//	//if (KeyManager::GetInst()->GetButton(VK_DOWN))
//	//{
//	//	pos.y += 5000 * TimeManager::GetInst()->GetDT();
//	//}
//	//Obj.SetPos(pos);
//	/*ㄴ게임을 그려주거나 위치좌표 등은 오브젝트 클래스로 이동합니다*/
//
//	SceneManager::GetInst()->Update();//이동후 이 함수들을 추가합니다.
//}