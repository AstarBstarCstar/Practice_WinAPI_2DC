#pragma once
class Source
{
private:
	wstring m_strKey;//���ҽ��� Ű(�̸�)
	wstring m_strPath;//���ҽ��� ���

public:
	void SetKey(const wstring& _strKey) { this->m_strKey = _strKey; }
	void SetPath(const wstring& _strPath) { this->m_strPath = _strPath; }

	wstring& GetKey() { return m_strKey; }//TODO: const?
	wstring& GetPath() { return m_strPath; }//TODO: const?

public:
		Source();
		~Source();
};

