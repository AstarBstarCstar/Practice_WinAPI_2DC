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

/*STL*/
#include <string>
#include <vector>

/*헤더선언*/
#include "TimeManager.h"
#include "CCore.h"
#include "SingleTon.h"
#include "Struct.h"
#include "KeyManager.h"

using namespace std;

/*:::DEFINE문:::*/
#define	WINSTARTX	100
#define	WINSTARTY	100
#define	WINSIZEX	1280//x해상도
#define	WINSIZEY	720//y해상도
#define	WINSTYLE	WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX //잘 모르겠지만 아마도 우측 상단 메뉴 구성인듯



/*전역변수 선언 (instance,handle)*/
extern HINSTANCE m_hInstance;	 /*어딘가에 이 변수가 있을거니까 그거 써도된다 의미(extern:외부변수) 함수로 치면 전방선언*/
extern HWND m_hWnd;              /*어딘가에 이 변수가 있을거니까 그거 써도된다 의미(extern:외부변수)*/

/*
1. 지역변수 : 함수 내에서 만들어짐		
2. 전역변수 : 함수 외부 전역에서 만들어짐					<-데이터 영역에 저장되며 프로그램 시작부터 끝까지 존재함.
3. 정적변수 : 함수 내부에서 만들어지지만 데이터 영역에 있음 <-데이터 영역에 존재하며 프로그램 시작부터 끝까지 존재하지만 정적변수가 선언된 위치에서만 쓸 수 있음.
4. 외부변수 : 다른 곳에서 만들어짐                        
5. 멤버변수 : 클래스 안에 선언되고 인스턴스가 생성될 당시에 만들어짐<-클래스 
*/