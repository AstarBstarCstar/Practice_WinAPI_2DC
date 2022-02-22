#pragma once
class KeyManager
{
	SINGLETON(KeyManager);

private:
	static const int VKEY_SIZE = 0xFF; //<- Ű ���� 255�� ���� �� ����ͼ� �����ų��

	/*���� Ű �Է»��¿� ���� Ű �Է»��¸� ����*/
	bool m_arrPrevKey[VKEY_SIZE];
	bool m_arrCurKey[VKEY_SIZE];

public:
	void Update();
	void Init();

	/*���� ��������, �ö󰣼���, �������� ����
	�ܽ�Ʈ�� ������� ������ ���� Ű���� �ٲ�� �ȵǱ� ����
	*/
	bool GetButton(const int key);
	bool GetButtonUP(const int key);
	bool GetButtonDown(const int key);
};


