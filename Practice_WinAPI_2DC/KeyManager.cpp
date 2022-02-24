#include "framework.h"
#include "KeyManager.h"


KeyManager::KeyManager()//Ű�Ŵ����� �����ڸ� �����մϴ�.
{
	for (int key = 0; key < VKEY_SIZE; key++)//��� Ű���� ������ ���� ���·� �ʱ�ȭ �մϴ�.
	{
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}

KeyManager::~KeyManager()
{
}

void KeyManager::Update()
{
	/*����Ŀ�� �Լ��� �̿��Ͽ�, ���� ���������� Ȯ���ϰ�, �ƴϸ� ��� Ű�Է��� �����մϴ�.*/
	HWND thisWnd = GetFocus();
	if (thisWnd != hWnd)
	{
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}
	//��� Ű �������� ��ŭ �ݺ��Ͽ� �Է»��¸� Ȯ���մϴ�.
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)//UNKNOWN:�̺κ� ������ �𸣰���. Ű ���ȴ��� �ȴ��ȴ����� �Լ� ���°� �˰ڴµ�, &0x8000 �̺κ��� ���ذ� �� ��.
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrPrevKey[key] = false;
		}
	}
}
void KeyManager::Init()
{
}

/*���� ��ư�� ���ȴ���, ��ư�� ��������, ��ư�� ������������ ���� �Լ��Դϴ�.*/
bool KeyManager::GetButton(const int key)
{
	return (true == m_arrCurKey[key] &&
			true == m_arrPrevKey[key]);
}
bool KeyManager::GetButtonUP(const int key)
{
	return (false == m_arrCurKey[key] &&
			true == m_arrPrevKey[key]);
}
bool KeyManager::GetButtonDown(const int key)
{
	return (true == m_arrCurKey[key] &&
			false == m_arrPrevKey[key]);
}