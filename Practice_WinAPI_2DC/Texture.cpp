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
{	/*TODO:!!!!!HELP!!!!! m_hBit �� HBITMAP ���� ����ȯ �ϰ�, ��ΰ��� �� ���Դµ�, m_hBit�� �޸𸮸� �� �н��ϴ�.*/																																							//�װ��� m_hBit �ڵ�� �޴´�.		/*���Ϸκ��� �ε� �� �����͸� ��Ʈ������ ����*/
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);//��θ� �ް�, ��Ʈ �� �����͸� �ε� �ϰ�, ������� 0,0(Defalut������), �ε�ɼ��� �����ϰ�, 
		/*assert(m_hBit);*/		//�ε��� �Ϸ� �ߴµ���, ��Ʈ�� �ڵ鰪�� �ΰ��̶��, �ε��� ���� �� ���̴�.(ID�� �ȳ�����->�ε�����)	

	m_DC = CreateCompatibleDC(CCore::GetInst()->GetMainDC());//�ھ��� ����DC����  CreateCompDC �� ���� ������, m_DC�� �־��ش�.  /*��Ʈ�ʰ� ���� �� DC*/

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_DC, m_hBit);//��Ʈ�ʰ��� DC�� ���� ��.
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);//GetObject:Ư�� ������Ʈ�� ���� ������ �˷��־�, �����ϴ� �Լ�       return: bm���μ���.
}

