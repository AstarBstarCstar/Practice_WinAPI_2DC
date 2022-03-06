#include "framework.h"
#include "Texture.h"
#include "Player.h"
Texture::Texture()
{
	m_DC ;
	m_hBit ;
	m_bitInfo;
}
Texture::~Texture()
{
	DeleteDC(m_DC);
	DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _strFPath)
{	/*TODO:!!!!!HELP!!!!! m_hBit 에 HBITMAP 으로 형변환 하고, 경로값은 잘 들어왔는데, m_hBit가 메모리를 못 읽습니다.*/																																							//그것을 m_hBit 핸들로 받는다.		/*파일로부터 로딩 한 데이터를 비트맵으로 생성*/
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);//경로를 받고, 비트 맵 데이터를 로딩 하고, 사이즈는 0,0(Defalut사이즈), 로드옵션을 지정하고, 
		/*assert(m_hBit);*/		//로딩을 완료 했는데도, 비트맵 핸들값이 널값이라면, 로딩에 실패 한 것이다.(ID가 안나왔음->로딩실패)	

	m_DC = CreateCompatibleDC(CCore::GetInst()->GetMainDC());//코어의 메인DC값을  CreateCompDC 를 통해 가져와, m_DC에 넣어준다.  /*비트맵과 연결 할 DC*/

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_DC, m_hBit);//비트맵과과 DC를 연결 함.
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);//GetObject:특정 오브젝트에 대한 정보를 알려주어, 리턴하는 함수       return: bm가로세로.
}

