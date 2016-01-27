#include "SoundBuffer.h"


SoundBuffer::SoundBuffer()
	: mDevice(audiere::OpenDevice())
	, mSounds()
{
}


void SoundBuffer::load(int soundID, const char* filename)
{
	if (!mSounds[soundID])
		mSounds[soundID] = audiere::OpenSoundEffect(mDevice, filename, audiere::MULTIPLE);
}


void SoundBuffer::play(int soundID, float volume, float pitch, float pan)
{
	if (mSounds[soundID])
	{
		mSounds[soundID]->setVolume(volume);
		mSounds[soundID]->setPitchShift(pitch);
		mSounds[soundID]->setPan(pan);
		mSounds[soundID]->play();
	}
}