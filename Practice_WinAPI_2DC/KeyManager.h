#pragma once

class KeyManager
{
	SINGLETON(KeyManager);

private:
	static const int VKEY_SIZE = 0xFF;		// VK�� �ִ� ����

	bool m_arrPrevKey[VKEY_SIZE];			// ���� Ű�� �Է»���
	bool m_arrCurKey[VKEY_SIZE];			// ���� Ű�� �Է»���
	fPoint m_fptCurMousePos;				// ���콺 ��ǥ

public:
	void Update();
	void Init();

	bool GetButton(const int key);			// Ű�� ������ ���� true
	bool GetButtonUP(const int key);		// Ű�� �ö� ���� true
	bool GetButtonDown(const int key);		// Ű�� ������ ���� true
	fPoint GetMousePos();					// ���콺 ��ǥ ���
};


