#include "framework.h"
#include "ResourceManager.h"

Texture* ResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strPath)//인자로 불러올 이름, 상대경로를 받음.
{
	Texture* pTexture = FindTexture(_strKey);
	if (nullptr != pTexture)
	{
		return pTexture;
	}

	wstring strFilePath = PathManager::GetInst()->GetContentsPath();
	strFilePath += _strPath;

	pTexture = new Texture;
	pTexture->Load(strFilePath);
	pTexture->SetKey(_strKey);
	pTexture->SetPath(_strPath);
	m_mapTex.insert(make_pair(_strKey, pTexture));//로드 된 이미지를 맵에 저장합니다.
	return pTexture;
}

Texture* ResourceManager::FindTexture(const wstring& _strKey)
{
	map<wstring, Texture*>::iterator iter = m_mapTex.find(_strKey);
	if (iter == m_mapTex.end())
	{
		return nullptr;
	}
	return iter->second;//TODO: iter->second의 뜻이 무엇?
}


ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{
	map<wstring, Texture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); iter++)
	{
		delete iter->second;
	}
}