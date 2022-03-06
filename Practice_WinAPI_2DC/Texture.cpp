#include "framework.h"
#include "Texture.h"

void Texture::Load(const wstring& _strFPath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);//��θ� �ް�, ��Ʈ �� �����͸� �ε� �ϰ�, ������� 0,0(Defalut������), �ε�ɼ��� �����ϰ�, 
																																																	//�װ��� m_hBit �ڵ�� �޴´�.
	if (nullptr == m_hBit)//�ε��� �Ϸ� �ߴµ���, ��Ʈ�� �ڵ鰪�� �ΰ��̶��, �ε��� ���� �� ���̴�.(ID�� �ȳ�����->�ε�����)
		return;//TODO: assert �� ������

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
