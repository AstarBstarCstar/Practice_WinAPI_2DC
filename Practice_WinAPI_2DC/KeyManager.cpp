#include "KeyManager.h"
#include "framework.h"

KeyManager::KeyManager()//키매니저의 생성자를 정의합니다.
{
	for (int key = 0; key < VKEY_SIZE; key++)//모든 키값을 눌리지 않은 상태로 초기화 합니다.
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
	//모든 키 사이즈의 만큼 반복하여 입력상태를 확인합니다.
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)//TODO:이부분 정말로 모르겠음.
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrPrevKey[key] = false;
		}
	}
}
void KeyManager::init()//여기는 생성자가 있으니까 없어도 되지 않을까?
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