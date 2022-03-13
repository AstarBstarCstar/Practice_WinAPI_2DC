#include "framework.h"
#include "SoundManager.h"
#include "CSound.h"


SoundManager::SoundManager()
{
	m_pSystem = nullptr;
}
SoundManager::~SoundManager()
{
		m_pSystem->release();
		m_pSystem->close();
}

void SoundManager::Init()
{
	FMOD_RESULT result;
	result = System_Create(&m_pSystem);
	assert(!result);
	result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	assert(!result);
}

void SoundManager::Update()
{
	/*중요! 프레임마다 1번 업데이트*/
	m_pSystem->update();
}

System* SoundManager::GetSystem()
{
	return m_pSystem;
}

void SoundManager::AddSound(wstring Key, wstring Path, bool bgm, bool loop)
{
	CSound* pSound;
	if (bgm)
	{
		pSound = ResourceManager::GetInst()->LoadBGM(Key, Path);
	}
	else
	{
		pSound = ResourceManager::GetInst()->LoadSound(Key, Path);
	}
	m_mapSound.insert(make_pair(Key, pSound));
}


void SoundManager::Play(wstring Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(Key);
	if (iter != m_mapSound.end())
		iter->second->Play();
}

void SoundManager::Resume(wstring Key)
{
	map<wstring, CSound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); iter++)
	{
		if (Key == iter->first)
		{
			iter->second->Resume();
			break;
		}
	}
}

void SoundManager::Pause(wstring Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(Key);
	if (iter != m_mapSound.end())
		iter->second->Pause();
}

void SoundManager::Stop(wstring Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(Key);
	if (iter != m_mapSound.end())
		iter->second->Stop();
}

bool SoundManager::SoundPlaying(wstring Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(Key);
	if (iter != m_mapSound.end())
		return iter->second->SoundPlaying();
	return false;
}

bool SoundManager::SoundPause(wstring Key)
{
	map<wstring, CSound*>::iterator iter = m_mapSound.find(Key);
	if (iter != m_mapSound.end())
		return iter->second->SoundPause();
	return false;
}
