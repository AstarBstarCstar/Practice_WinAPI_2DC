#pragma once
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")

class CSound : public Source
{
private:
	FMOD::System*	    m_pSystem;
	FMOD::Sound*		m_pSound;
	FMOD::Channel*		m_pChannel;

public:
	void Load(const wstring& _strPath);
	void Play();
	void Resume();
	void Pause();
	void Stop();
	
	bool SoundPlaying();
	bool SoundPause();

public:
	CSound();
	~CSound();
};

