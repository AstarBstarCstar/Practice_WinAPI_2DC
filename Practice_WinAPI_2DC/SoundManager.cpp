#include "framework.h"
#include "SoundManager.h"
#include "Sound.h"


SoundManager::SoundManager()
{
	m_pSystem = nullptr;
}
SoundManager::~SoundManager()
{
}

void SoundManager::Init()
{
	FMOD_RESULT Result;
	FMOD::System_Create(&m_pSystem);
	assert(!Result);
	Result = m_pSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	assert(!Result);
}

void SoundManager::Update()
{
	/*중요! 프레임마다 1번 업데이트*/
	m_pSystem->update();
}

const System* SoundManager::GetSystem()
{
	return m_pSystem;
}

void SoundManager::AddSound(wstring Key, wstring Path, bool bgm)
{
	Sound* pSound = ResourceManager::GetInst()->LoadSound(Key,Path);
	pSound->Load();
	m_mapSound.insert(make_pair(Key, pSound));
}


void SoundManager::Play(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		return;

	iter->second->Play();
}

void SoundManager::Resume(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		return;

	iter->second->Resume();
}

void SoundManager::Pause(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		return;

	iter->second->Pause();
}

void SoundManager::Stop(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		return;

	iter->second->Stop();
}

bool SoundManager::SoundPlaying(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		assert(nullptr);
	return iter->second->SoundPlaying();
}

bool SoundManager::SoundPause(wstring Key)
{
	map<wstring, Sound*>::iterator iter = m_mapSound.find(Key);
	if (iter == m_mapSound.end())
		assert(nullptr);
	return iter->second->SoundPause();
}
