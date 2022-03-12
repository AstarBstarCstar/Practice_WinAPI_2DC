#pragma once
#include "Source.h"
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")
using namespace FMOD;

class CSound : public Source
{
private:
	/*System*	    m_pSystem;*/
	Sound*		m_pSound;
	Channel*		m_pChannel;

public:
	void Load(const wstring& _strPath,bool bgm);
	void Play();
	void Resume();
	void Pause();
	void Stop();
	
	bool SoundPlaying();
	bool SoundPause();
	void SetLoop(bool loop);

public:
	CSound();
	~CSound();
};

