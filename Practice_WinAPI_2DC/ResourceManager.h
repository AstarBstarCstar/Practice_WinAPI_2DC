#pragma once

class Texture;

class ResourceManager
{
	SINGLETON(ResourceManager);
private:
	map<wstring, Texture*> m_mapTex;
public:
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strPath);
	Texture* FindTexture(const wstring& _strKey);
};

