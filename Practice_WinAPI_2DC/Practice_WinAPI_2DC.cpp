// Practice_WinAPI_2DC.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//
#include "framework.h"
#include "Practice_WinAPI_2DC.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다. 프로그램에 대한 시작 핸들값
HWND hWnd;                          //<-왜인지 모르겠는데 얘를 안써서(누락되서) 한참 쩔쩔매다 해결됨
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다. 타이틀       옆 변수들은 typedef로 변수 이름 바꾼것
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다. 


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



/*이곳이 윈도우 메인이며, 윈도우 메인의 역할은 1.윈도우창 세팅 후 화면에 띄우기, 2.메세지 루프*/
/*_In_ : SAL 주석 - 자주 사용되는 주석을 적지 않고 키워드로 사용*/
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,           /*hInstance : 실행된 프로세스의 시작 주소. 인스턴스 핸들*/
    _In_opt_ HINSTANCE hPrevInstance,    /*hPrevInstance : 이전 실행 인스턴스 핸들 hprev<-*/
    _In_ LPWSTR    lpCmdLine,            /*lpCmdLine : 명령으로 입력된 프로그램의 인수(cmd)  ex) cmd에 프로그램 드래그 */
    _In_ int       nCmdShow)             /*nCmdShow:프로그램이 시작될 형태*/

{    /*사용되지 않은 매개변수 정의 (이전버전에 쓰던거라던지)*/
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    /*리소스 뷰의 string table 용도*/
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PRACTICEWINAPI2DC, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    /*단축키 정보*/
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PRACTICEWINAPI2DC));

    //    MSG msg;/*메세지 정의*/
    //     /*이부분은 GetMessage 부분 픽메세지로 바꿨으니 한번 참고할것*/
    //    // 기본 메시지 루프입니다:
    //    /*여기서 메시지 큐에서 메시지가 확인 될 때까지 대기(무한루프)*/
    //    /*메시지 큐에 msg.message == WM_QUIT 인 경우 false를 반환한다*/
    //    while (GetMessage(&msg, nullptr, 0, 0))//GetMessage : 메시지 큐에 메시지가 없으면 대기함. 메시지가 들어왔다면 True 를 반환
    //    {                                     /*PeekMessage : 메시지 큐에 메시지가 없다면 false, 있다면 true 반환*/
    //        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) //TranslateAccelerator : 단축키 대한 처리
    //        {
    //            TranslateMessage(&msg);  //키보드 입력 메시지 처리 담당
    //            DispatchMessage(&msg);   //
    //        }
    //    }
    //
    //    return (int) msg.wParam;
    //}


    CCore::GetInst()->Init();
    /*픽메세지를 통해 게임 처리 가능*/
    MSG msg; /*GetMessage -> PeekMessage 로 바꿈  !!!중요!!!*/
    while (1)/*이전 메시지 대기 상태 유지에서 현재 픽메세지의 메시지가 없는 99.99% 상황에서 게임 상황을 처리함*/
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            CCore::GetInst()->Update();
            CCore::GetInst()->Render();
        }
    }

    return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;/*윈도우 창의 정보를 저장하기 위한 구조체이다*/

    wcex.cbSize = sizeof(WNDCLASSEX);//구조체의 크기 설정

    wcex.style          = CS_HREDRAW | CS_VREDRAW;              // 윈도우 클래스의 스타일 지정하는 얘
    wcex.lpfnWndProc    = WndProc;                               // 윈도우의 메세지를 처리하는 함수 WndProc
    wcex.cbClsExtra     = 0;                                   // 윈도우 클래스에서 사용하고자 하는 여분의 메모리의 양            
    wcex.cbWndExtra     = 0;                                   // cbClsExtra와 유사하지만 개별윈도우에서 사용하고자 하는 여분의 메모리의 양
    wcex.hInstance      = hInstance;                             // 윈도우 클래스를 등록한 인스턴스 핸들값 지정
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRACTICEWINAPI2DC));//윈도우의 아이콘
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);       //커서설정
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);            //윈도우 작업영역에 칠한 배경 
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PRACTICEWINAPI2DC);  //윈도우 메뉴 지정
    wcex.lpszClassName  = szWindowClass;                      //윈도우 클래스 이름
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));//작은 아이콘 리소스 로드

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(//UNKNOWN:  HWND hWnd  를 HWND를 지우고 hWnd만 적으니 창 두개가 사라지고 잘 나오는 이유? 아마도 extern을 했엇으니 또해서 그런듯?
                            szWindowClass,       //클래스의 이름 
                             szTitle,             //윈도우 타이틀 이름
                             WINSTYLE,            //윈도우 스타일, 내부 뜯어서 보여주기
                             WINSTARTX,           //윈도우 화면의 X축
                             WINSTARTY,           //윈도우 화면의 Y축
                             WINSIZEX,            //가로 크기
                             WINSIZEY,            //세로 크기  
                             nullptr,             //부모 윈도우
                             nullptr,             //메뉴 핸들
                             hInstance,           //인스턴스 지정
                             nullptr);            //추가 매개변수

   if (!hWnd)
   {
      return FALSE;//hWnd제데로 호출 안 될시 꺼버린다
   }

   /*실제 윈도우 크기를 구하기 위해서 Adjust를 사용함*/
   RECT rc;
   rc.left = 0;
   rc.top = 0;
   rc.right = WINSIZEX;
   rc.bottom = WINSIZEY;

   /*실제 윈도우 창이 크기에 맞게 나온다*/
   AdjustWindowRect(&rc, WINSTYLE, false);

   /*위 RECT정보로 윈도우 사이즈를 세팅*/
   SetWindowPos(hWnd, NULL, WINSTARTX, WINSTARTY, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);

   ShowWindow(hWnd, nCmdShow);  //윈도우 보여주기
   UpdateWindow(hWnd);          //윈도우 업데이트 하기

   return TRUE;
}
/*
WndPrc : 메시지를 운영체제에 전달함. 강제로 운영체제가 호출함.
hWnd : 메시지가 어느 윈도우를 대상으로 전달되었는지 구분한다.
message : 메시지 구분번호
wParam : unsigned int 메시지의 매개변수 1
lParam : unsigned long 메시지의 매개변수 2
*/
//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

    case WM_PAINT://윈도우의 작업영역이 다시 그려져야 할 때 실행됨 (무효화영역 발생시 실행?
    {
        PAINTSTRUCT ps;
        /*Device Context 만들어서 ID를 반환*/
        HDC hdc = BeginPaint(hWnd, &ps);/*HDC = 그리기 툴 도구모음 같은 정도*/
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        //HPEN hNewPen = CreatePen(PS_DASH, 3, RGB(255, 0, 0));/*펜스타일 정의*/
        //HBRUSH hNewBrush = CreateSolidBrush(RGB(0, 255, 0));/*브러쉬 스타일 정의*/

        //HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);/*만든 펜 스타일 적용후 hOldPen에 적용*/
        //HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);/*만든 브러쉬 스타일 적용후 hOldBrush에 적용*/
       
        //Rectangle(hdc, (g_rectPos.x - g_rectXSize), (g_rectPos.y - g_rectYSize), (g_rectPos.x + g_rectXSize), (g_rectPos.y + g_rectYSize));/*나는 사각형을 이러한 사이즈로 그릴거야*/
        //SelectObject(hdc, hOldPen);
        //SelectObject(hdc, hOldBrush);

        //DeleteObject(hOldPen);/*다 그렸으면 올드펜을 반환할것*/
        //DeleteObject(hOldBrush);/*다 그렸으면 올드브러쉬를 반환할것*/
        EndPaint(hWnd, &ps);/**/
    }
        break;

    case WM_DESTROY:/*윈도우 종료시 실행*/
        PostQuitMessage(0);/*메시지큐 뒤에 WM_QUIT 입력*/
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


//        /*
//        DC 의 목적지는 hWnd
//        DC 의 펜은 기본펜이다(검정)
//        DC 의 브러쉬는 기본 브러쉬이다(white)
//        */

//        /*직접 펜과 브러쉬를 만들어서 DC에 적용*/
//        HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
//        HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

//        /*기존의 펜과 브러쉬 아이디를 받아 저장*/
//        HPEN hOldPen = (HPEN)SelectObject(hdc, hRedPen);
//        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);

//        Ellipse(hdc, x - 100, y - 100, x + 100, y + 100);
//        Rectangle(hdc, g_keypos.x - 50, g_keypos.y - 50, g_keypos.x + 50, g_keypos.y + 50);

//        /*DC의 펜과 브러쉬를 원래대로 되돌림*/
//        SelectObject(hdc, hOldBrush);
//        SelectObject(hdc, hOldPen);

//    EndPaint(hWnd, &ps);
//}