#include "framework.h"
#include "PathManager.h"


void PathManager::Init()
{
	GetCurrentDirectory(255,m_ContentsPath);//현재 윈도우가 실행되었을 위치(exe파일의 위치)를 받아오는 함수.  (최대몇자 ,현재 경로를 담을 변수)
	int PathLen = wcslen(m_ContentsPath);//문자의 길이를 알아내는 함수 wcslen(); null문자를 만날때 까지 체크함.

	for (int i = PathLen - 1; i >= 0; i--)
	{
		if (m_ContentsPath[i] == '\\')//i번째 문자열을 확인 했더니 구분문자\\라면, null문자를 넣어서 경로를 끊어준 뒤 반복문 종료.
		{
			m_ContentsPath[i] = '\0';//디버그 후 출력 하니 TestOutput 폴더에서 끊긴것을 확인 할 수 있음. /*Debug:C:\Users\MoonS\source\repos\Practice_WinAPI_2DC\TestOutput*/
			break;
		}
	}
	wcscat_s(m_ContentsPath,255,L"\\Release\\contents\\");//문자열을 이어 붙여주는 함수 wcscat_s();   붙일 대상, 배열사이즈 , 붙일 문자열    이것을 통해서 항상 경로를 찾아낼 수 있다.
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
