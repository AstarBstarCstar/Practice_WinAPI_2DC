#pragma once
class KeyManager
{
	SINGLETON(KeyManager);

private:
	static const int VKEY_SIZE = 0xFF; //<- 키 갯수 255개 전부 다 갖고와서 적용시킬것

	/*이전 키 입력상태와 현재 키 입력상태를 정의*/
	bool m_arrPrevKey[VKEY_SIZE];
	bool m_arrCurKey[VKEY_SIZE];

public:
	void Update();
	void Init();

	/*각각 눌린상태, 올라간순간, 누른순간 정의
	콘스트로 묶어놓은 이유는 원래 키값이 바뀌면 안되기 때문
	*/
	bool GetButton(const int key);
	bool GetButtonUP(const int key);
	bool GetButtonDown(const int key);
};


