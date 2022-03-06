#pragma once
class PathManager
{
	SINGLETON(PathManager);
private:
	wchar_t			m_ContentsPath[255];//윈도우의 최대 글자 경로 255, 경로를 저장하는 변수

public:
	void Init();
	const wchar_t* GetContentsPath() { return m_ContentsPath; } //const로 묶은 이유는, 찾은 경로가 훼손되면 안 돼기 때문.
};

