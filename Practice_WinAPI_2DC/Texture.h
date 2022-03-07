#pragma once
#include "Source.h"
class Texture : public Source
{
public:
	HDC				m_DC;
	HBITMAP		m_hBMP;
	BITMAP		m_bitInfo;//������ ���� ��Ʈ�� ����ü

public:
	void Load(const wstring& _strFPath);

	UINT Width() { return m_bitInfo.bmWidth; }
	UINT Heigh() { return m_bitInfo.bmHeight; }
	HDC GetDC() { return m_DC; }


public:
	Texture();
	~Texture();
};

