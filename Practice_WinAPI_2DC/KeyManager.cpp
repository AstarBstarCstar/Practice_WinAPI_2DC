#include "KeyManager.h"
#include "framework.h"

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

void KeyManager::update()
{
	//��� Ű �������� ��ŭ �ݺ��Ͽ� �Է»��¸� Ȯ���մϴ�.
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)//TODO:�̺κ� ������ �𸣰���.
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrPrevKey[key] = false;
		}
	}
}
void KeyManager::init()//����� �����ڰ� �����ϱ� ��� ���� ������?
{
}

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