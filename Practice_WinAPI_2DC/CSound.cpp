#include "framework.h"
#include "CSound.h"
CSound::CSound()
{
	m_pChannel = nullptr;
	 m_pSound = nullptr;
}

CSound::~CSound()
{
	Stop();
	if (nullptr != m_pSound)
	{
		m_pSound->release();
	}//TODO:Help!이부분에서 자꾸 예외처리 발생 
}

void CSound::Load(const wstring& _strPath,bool bgm)
{
	char str[255];
	wcstombs_s(nullptr, str, _strPath.c_str(), 255);

	if (bgm)
	{
		SoundManager::GetInst()->GetSystem()->createStream(str, FMOD_LOOP_NORMAL, 0, &m_pSound);
	}
	else
	{
		SoundManager::GetInst()->GetSystem()->createSound(str, FMOD_LOOP_OFF, 0, &m_pSound);
	}
}

void CSound::Play()
{
	SoundManager::GetInst()->GetSystem()->playSound(m_pSound, 0, false, &m_pChannel);
	assert(m_pChannel);
}

void CSound::Resume()
{
	assert(m_pChannel);
	m_pChannel->setPaused(true);
}

void CSound::Pause()
{
	assert(m_pChannel);
		m_pChannel->setPaused(true);
}

void CSound::Stop()
{
	assert(m_pChannel);
	m_pChannel->stop();
}

bool CSound::SoundPlaying()
{
	bool playing = false;
	assert(m_pChannel);
	m_pChannel->isPlaying(&playing);

	return playing;
}

bool CSound::SoundPause()
{
	bool paused = false;
	assert(m_pChannel);
	m_pChannel->getPaused(&paused);

	return paused;
}

void CSound::SetLoop(bool loop)
{
	if (loop)
	{
		m_pSound->setMode(FMOD_LOOP_NORMAL);
	}
	else
	{
		m_pSound->setMode(FMOD_LOOP_OFF);
	}
}

