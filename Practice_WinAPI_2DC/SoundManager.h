#pragma once
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")
using namespace FMOD;

class SoundManager
{
	SINGLETON(SoundManager);

private:
	map<wstring, Sound*>m_mapSound;
	System* m_pSystem;
public:
	void Init();
	void Update();

	const System* GetSystem();

	void AddSound(wstring Key, wstring Path, bool bgm);
	void Play(wstring Key);
	void Resume(wstring Key);
	void Pause(wstring Key);
	void Stop(wstring Key);
	
	bool SoundPlaying(wstring Key);
	bool SoundPause(wstring Key);
	
};

