#include "framework.h"
#include "CSound.h"
CSound::CSound()
{
	m_pChannel = nullptr;
	 m_pSystem = nullptr;
	 m_pSound = nullptr;
}

CSound::~CSound()
{
}

void CSound::Load(const wstring& _strPath)
{
	char str[255];
	wcstombs_s(nullptr, str, _strPath.c_str(), 255);
	SoundManager::GetInst()->GetSystem()->createsound(str, FMOD_DEFAULT, nullptr, &m_pSound);
}

void CSound::Play()
{
	//FMOD_RESULT Result = m_pSystem->playSound(m_pSound, 0, false, &m_pChannel);
	//assert(!Result);
}

void CSound::Resume()
{
	
}

void CSound::Pause()
{
}

void CSound::Stop()
{
}

bool CSound::SoundPlaying()
{
}

bool CSound::SoundPause()
{
}

