#pragma once

class Texture;
class CSound;

class ResourceManager
{
	SINGLETON(ResourceManager);
private:
	map<wstring, Texture*> m_mapTex;
	map<wstring, CSound*>m_mapSound;
	CSound* m_pBGM;							// BGM ���ҽ��� ���� ����
public:
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strPath);
	Texture* FindTexture(const wstring& _strKey);

	CSound* FindSound(const wstring& _Key);
	CSound* LoadSound(const wstring& _Key,const wstring& _RelPath);
	CSound* LoadBGM(const wstring& strKey, const wstring& strRelativePath);		// BGM �ҷ����� �̹� �ִ� ��� �ִ� BGM ��ȯ
};

