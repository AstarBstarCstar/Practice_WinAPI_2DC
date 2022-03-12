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
	HWND curWnd = GetFocus();
	if (hWnd != curWnd)
	{
		// �����찡 ����(Focus)�� ���°� �ƴ� ��� Ű�Է��� ������Ŵ
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}

	// ��� Ű �����ŭ �ݺ��ϸ� �Է»��¸� Ȯ��
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrCurKey[key] = false;
		}
	}
	// Mouse ��ǥ ���
	POINT ptPos = {};
	// GetCursorPos() �����쿡�� ����� �»�� ���� ���콺�� ��ǥ�� ��ȯ
	GetCursorPos(&ptPos);
	// ����� �»�� ���� ���콺 ��ǥ�� ���� ������ ���� ���콺 ��ġ�� ���
	ScreenToClient(hWnd, &ptPos);

	m_fptCurMousePos = fPoint((float)ptPos.x, (float)ptPos.y);
}
void KeyManager::Init()
{
}

/*���� ��ư�� ���ȴ���, ��ư�� ��������, ��ư�� ������������ ���� �Լ��Դϴ�.*/
bool KeyManager::GetButton(const int key)
{
	return (true == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}
bool KeyManager::GetButtonUP(const int key)
{
	return (false == m_arrCurKey[key] && true == m_arrPrevKey[key]);
}
bool KeyManager::GetButtonDown(const int key)
{
	return (true == m_arrCurKey[key] && false == m_arrPrevKey[key]);
}
fPoint KeyManager::GetMousePos()
{
	return m_fptCurMousePos;
}