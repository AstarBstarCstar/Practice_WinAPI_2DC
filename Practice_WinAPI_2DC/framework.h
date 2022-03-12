// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN// 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

// Windows 헤더 파일
#include <windows.h>
#pragma comment ( lib , "Msimg32.lib" )

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <assert.h>
#include <math.h>
#include <crtdbg.h>

/*STL*/
#include <vector>
#include <map>
#include <string>
using std::vector;
using std::map;
using std::make_pair;
using std::string;
using std::wstring;

/*:::DEFINE문:::*/
#define	WINSTARTX	100
#define	WINSTARTY	100
#define	WINSIZEX	1280//x해상도
#define	WINSIZEY	720//y해상도
#define	WINSTYLE	WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX //잘 모르겠지만 아마도 우측 상단 메뉴 구성인듯
#define PI			3.1415926535f

#define	fDT			TimeManager::GetInst()->GetDT();

#define Key(key)		KeyManager::GetInst()->GetButton(key)
#define KeyUp(key)		KeyManager::GetInst()->GetButtonUP(key)
#define KeyDown(key)	KeyManager::GetInst()->GetButtonDown(key)





/*:::열거형 클래스 정의부:::*/
enum class ENUM_GAMEOBJ//ENUM_GAMEOBJ를 열거형 클래스로 선언합니다.
{
	DEFAULT,
	PLAYER,
	MONSTER,
	BULLET,

	SIZE
};
enum class ENUM_SCENE//열거형 클래스로 ENUM_SCENE을 선언합니다.
{
	TOOL,
	START,
	STAGE_1,
	STAGE_2,

	SIZE
};

/*
1. 지역변수 : 함수 내에서 만들어짐
2. 전역변수 : 함수 외부 전역에서 만들어짐					<-데이터 영역에 저장되며 프로그램 시작부터 끝까지 존재함.
3. 정적변수 : 함수 내부에서 만들어지지만 데이터 영역에 있음 <-데이터 영역에 존재하며 프로그램 시작부터 끝까지 존재하지만 정적변수가 선언된 위치에서만 쓸 수 있음.
4. 외부변수 : 다른 곳에서 만들어짐
5. 멤버변수 : 클래스 안에 선언되고 인스턴스가 생성될 당시에 만들어짐<-클래스
*/

/*:::전역변수 선언 (instance,handle):::*/
extern HINSTANCE hInst;	 /*어딘가에 이 변수가 있을거니까 그거 써도된다 의미(extern:외부변수) 함수로 치면 전방선언*/
extern HWND hWnd;              /*어딘가에 이 변수가 있을거니까 그거 써도된다 의미(extern:외부변수)*/

/*헤더선언부*/ 
//TODO:(HELP)헤더선언을 아래로 내렸더니 오류가 사라진 이유 알아보기 (당시 열거형 클래스보다 위에 선언되어있었음.)
#include "SingleTon.h"
#include "TimeManager.h"
#include "CCore.h"
#include "Struct.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "PathManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "SoundManager.h"
//#include "UIManager.h"

