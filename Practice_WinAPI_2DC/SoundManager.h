#pragma once
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")
using namespace FMOD;

class SoundManager
{
	SINGLETON(SoundManager);

private:
	map<wstring, CSound*>m_mapSound;
	System* m_pSystem;
public:
	System* GetSystem();

	void Init();
	void Update();

	void AddSound(wstring Key, wstring Path,bool bgm = false, bool loop = false);
	void Play(wstring Key);
	void Resume(wstring Key);
	void Pause(wstring Key);
	void Stop(wstring Key);
	
	bool SoundPlaying(wstring Key);
	bool SoundPause(wstring Key);
	
};

