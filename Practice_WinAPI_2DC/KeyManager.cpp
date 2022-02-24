#include "framework.h"
#include "KeyManager.h"


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

void KeyManager::Update()
{
	/*겟포커스 함수를 이용하여, 현재 윈도우인지 확인하고, 아니면 모든 키입력을 해제합니다.*/
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
	//모든 키 사이즈의 만큼 반복하여 입력상태를 확인합니다.
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)//UNKNOWN:이부분 정말로 모르겠음. 키 눌렸는지 안눌렸는지의 함수 쓰는건 알겠는데, &0x8000 이부분이 이해가 안 감.
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

/*각각 버튼이 눌렸는지, 버튼이 떼졌는지, 버튼이 눌려졌는지에 대한 함수입니다.*/
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