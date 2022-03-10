#pragma once

class Texture;

class ResourceManager
{
	SINGLETON(ResourceManager);
private:
	map<wstring, Texture*> m_mapTex;
	map<wstring, Sound*>m_mapSound;
public:
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strPath);
	Texture* FindTexture(const wstring& _strKey);

	Sound* FindSound(const wstring& Key);
	Sound* LoadSound(const wstring& Key);
};

