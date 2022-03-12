#include "framework.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "CSound.h"

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
	return iter->second;
}

CSound* ResourceManager::FindSound(const wstring& _Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(_Key);
	{
		if (iter == m_mapSound.end())
		{
			return nullptr;
		}
		return iter->second;
	}
}

CSound* ResourceManager::LoadSound(const wstring& _Key, const wstring& _RelPath)
{
	// Sound를 불러오기 전 자료구조에 이미 Sound가 있는지 확인
	CSound* pSound = FindSound(_Key);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound 저장 경로 확인
	wstring strFilePath = PathManager::GetInst()->GetRelativeContentPath();
	strFilePath += _RelPath;

	// Sound 생성 후 저장
	pSound = new CSound;
	pSound->Load(strFilePath,false);
	pSound->SetKey(_Key);
	pSound->SetPath(_RelPath);

	m_mapSound.insert(make_pair(_Key, pSound));

	return pSound;
}

CSound* ResourceManager::LoadBGM(const wstring& strKey, const wstring& strRelativePath)
{
	CSound* pBGM = m_pBGM;
	if (nullptr != pBGM)
		return pBGM;

	// Sound 저장 경로 확인
	wstring strFilePath = PathManager::GetInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound 생성 후 저장
	pBGM = new CSound;
	pBGM->Load(strFilePath, true);
	pBGM->SetKey(strKey);
	pBGM->SetPath(strRelativePath);

	m_pBGM = pBGM;

	return pBGM;
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

	for (map<wstring, CSound*>::iterator iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
	m_mapSound.clear();
}