#pragma once
class PathManager
{
	SINGLETON(PathManager);
private:
	wchar_t			m_ContentsPath[255];//�������� �ִ� ���� ��� 255, ��θ� �����ϴ� ����

public:
	void Init();
	const wchar_t* GetContentsPath() { return m_ContentsPath; } //const�� ���� ������, ã�� ��ΰ� �ѼյǸ� �� �ű� ����.
};

