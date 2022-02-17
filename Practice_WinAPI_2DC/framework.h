// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>



/*:::DEFINE문:::*/
#define	WINSTARTX	100
#define	WINSTARTY	100
#define	WINSIZEX	1280//x해상도
#define	WINSIZEY	720//y해상도
#define	WINSTYLE	WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX //잘 모르겠지만 아마도 우측 상단 메뉴 구성인듯



/*전역변수 선언 (instance,handle)*/
extern HINSTANCE m_hInstance;
extern HWND m_hWnd;              /*TODO:이부분 당최 모르겠다*/