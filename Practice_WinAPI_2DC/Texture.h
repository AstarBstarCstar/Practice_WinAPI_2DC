#pragma once
#include "Source.h"
class Texture : public Source
{
private:
	HDC				m_DC;
	HBITMAP		m_hBit;

public:
	void Load(const wstring& _strFPath);



public:
	Texture();
	~Texture();
};

