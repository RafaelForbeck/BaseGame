#pragma once

#include "Audiere.h"
#include <map>

class SoundBuffer
{
public:
	SoundBuffer();

	void load(int soundID, const char* filename);
	void play(int soundID, float volume = 1.f, float pitch = 1.f, float pan = .0f);

private:
	audiere::AudioDevicePtr mDevice;
	std::map<int, audiere::SoundEffectPtr> mSounds;
};
