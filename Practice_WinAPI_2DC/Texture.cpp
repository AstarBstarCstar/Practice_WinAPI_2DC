#include "framework.h"
#include "Texture.h"

void Texture::Load(const wstring& _strFPath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);//경로를 받고, 비트 맵 데이터를 로딩 하고, 사이즈는 0,0(Defalut사이즈), 로드옵션을 지정하고, 
																																																	//그것을 m_hBit 핸들로 받는다.
	if (nullptr == m_hBit)//로딩을 완료 했는데도, 비트맵 핸들값이 널값이라면, 로딩에 실패 한 것이다.(ID가 안나왔음->로딩실패)
		return;//TODO: assert 로 막을것

}

Texture::Texture()
{
	m_DC = 0;
	m_hBit = 0;
}

Texture::~Texture()
{
	DeleteDC(m_DC);
	DeleteObject(m_hBit);
}
