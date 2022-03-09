#include "framework.h"
#include "CCore.h"

CCore::CCore()
{
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
}

/*���� �ھ� ���� ������ DC �ڵ鰪 �ݳ� �Ҹ��ڿ����Դϴ�*/
CCore::~CCore()
{
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

/*������ ������ �Էµ� �������ִ� �����Դϴ�*/
void CCore::Update()
{
	KeyManager::GetInst()->Update();
	TimeManager::GetInst()->Update();
	SceneManager::GetInst()->Update();
	/*UIManager::GetInst->Update();*/
}

/*������ �׷��ִ� �����Դϴ�*/
void CCore::Render()
{
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	SceneManager::GetInst()->Render(m_hMemDC);

	/*������ ��ܿ� �������� ǥ���ϴ� �ڵ��Դϴ�*/
	WCHAR strFPS[6];

	swprintf_s(strFPS, L"%5d", TimeManager::GetInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

/*�ھ �ʱ�ȭ �ϴ� �����Դϴ�.*/
void CCore::Init()
{
	PathManager::GetInst()->Init();
	TimeManager::GetInst()->Init();
	KeyManager::GetInst()->Init();
	SceneManager::GetInst()->Init();
	

	m_hDC = GetDC(hWnd);

	/*���� ���۸��� �޸� DC�� �޸� ��Ʈ���� �����ϴ� �ڵ��Դϴ�*/
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
//	//UNKNOWN: ������ ��ũ extern �����ϴ� ���ڱ� �ȵǴ��� �� �� ���� �˾ƺ���
//
//	//fPoint pos = Obj.GetPos();
//	///*GetAsuncKeyState: �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ���ϴ� �Լ��Դϴ�.*/
//	//if (KeyManager::GetInst()->GetButton(VK_LEFT))
//	//{/*SOLVED:�簢�� �̻��ϰ� �����̴� �ǿ� ���ؼ� Ÿ�� �Լ��� ������ ����(Ȯ��)*/
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
//	/*�������� �׷��ְų� ��ġ��ǥ ���� ������Ʈ Ŭ������ �̵��մϴ�*/
//
//	SceneManager::GetInst()->Update();//�̵��� �� �Լ����� �߰��մϴ�.
//}
//
///*������ �׷��ִ� �����Դϴ�*/
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
//	/*�������� �׷��ְų� ��ġ��ǥ ���� ������Ʈ Ŭ������ �̵��մϴ�*/
//
//	SceneManager::GetInst()->Render(m_hMemDC);//Ŭ������ �̵� �� �� �Լ��� �߰��մϴ�.
//
//	/*������ ��ܿ� �������� ǥ���ϴ� �ڵ��Դϴ�*/
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
//	//UNKNOWN: ������ ��ũ extern �����ϴ� ���ڱ� �ȵǴ��� �� �� ���� �˾ƺ���
//
//	//fPoint pos = Obj.GetPos();
//	///*GetAsuncKeyState: �޽��� ť�� Ű �Է��� �޴� ����� �ƴ� ���� ������ Ű �Է»��¸� Ȯ���ϴ� �Լ��Դϴ�.*/
//	//if (KeyManager::GetInst()->GetButton(VK_LEFT))
//	//{/*SOLVED:�簢�� �̻��ϰ� �����̴� �ǿ� ���ؼ� Ÿ�� �Լ��� ������ ����(Ȯ��)*/
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
//	/*�������� �׷��ְų� ��ġ��ǥ ���� ������Ʈ Ŭ������ �̵��մϴ�*/
//
//	SceneManager::GetInst()->Update();//�̵��� �� �Լ����� �߰��մϴ�.
//}