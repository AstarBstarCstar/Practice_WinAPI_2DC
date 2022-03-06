#pragma once
class Source
{
private:
	wstring m_strKey;//리소스의 키(이름)
	wstring m_strPath;//리소스의 경로

public:
	void SetKey(const wstring& _strKey) { this->m_strKey = _strKey; }
	void SetPath(const wstring& _strPath) { this->m_strPath = _strPath; }

	wstring& GetKey() { return m_strKey; }//TODO: const?
	wstring& GetPath() { return m_strPath; }//TODO: const?

public:
		Source();
		~Source();
};

