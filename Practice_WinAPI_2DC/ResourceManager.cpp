#include "framework.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "CSound.h"

Texture* ResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strPath)//���ڷ� �ҷ��� �̸�, ����θ� ����.
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
	m_mapTex.insert(make_pair(_strKey, pTexture));//�ε� �� �̹����� �ʿ� �����մϴ�.
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
	// Sound�� �ҷ����� �� �ڷᱸ���� �̹� Sound�� �ִ��� Ȯ��
	CSound* pSound = FindSound(_Key);
	if (nullptr != pSound)
	{
		return pSound;
	}

	// Sound ���� ��� Ȯ��
	wstring strFilePath = PathManager::GetInst()->GetRelativeContentPath();
	strFilePath += _RelPath;

	// Sound ���� �� ����
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

	// Sound ���� ��� Ȯ��
	wstring strFilePath = PathManager::GetInst()->GetRelativeContentPath();
	strFilePath += strRelativePath;

	// Sound ���� �� ����
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