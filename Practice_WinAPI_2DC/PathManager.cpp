#include "framework.h"
#include "PathManager.h"


void PathManager::Init()
{
	GetCurrentDirectory(255,m_ContentsPath);//���� �����찡 ����Ǿ��� ��ġ(exe������ ��ġ)�� �޾ƿ��� �Լ�.  (�ִ���� ,���� ��θ� ���� ����)
	int PathLen = wcslen(m_ContentsPath);//������ ���̸� �˾Ƴ��� �Լ� wcslen(); null���ڸ� ������ ���� üũ��.

	for (int i = PathLen - 1; i >= 0; i--)
	{
		if (m_ContentsPath[i] == '\\')//i��° ���ڿ��� Ȯ�� �ߴ��� ���й���\\���, null���ڸ� �־ ��θ� ������ �� �ݺ��� ����.
		{
			m_ContentsPath[i] = '\0';//����� �� ��� �ϴ� TestOutput �������� ������� Ȯ�� �� �� ����. /*Debug:C:\Users\MoonS\source\repos\Practice_WinAPI_2DC\TestOutput*/
			break;
		}
	}
	wcscat_s(m_ContentsPath,255,L"\\Release\\contents\\");//���ڿ��� �̾� �ٿ��ִ� �Լ� wcscat_s();   ���� ���, �迭������ , ���� ���ڿ�    �̰��� ���ؼ� �׻� ��θ� ã�Ƴ� �� �ִ�.
	/*Debug:C:\Users\MoonS\source\repos\Practice_WinAPI_2DC\TestOutput\Release\contents\*/

}

PathManager::PathManager()
{
	m_ContentsPath;
}

PathManager::~PathManager()
{
}

const wchar_t* PathManager::GetRelativeContentPath()
{
#ifdef _DEBUG
	return L"..\\Release\\contents\\";
#else
	return L"contents\\";
#endif
}
