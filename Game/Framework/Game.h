#pragma once

#include "GameState.h"
#include "Audio/SoundBuffer.h"
#include "Graphics/TextureManager.h"

class Game
{
public:
	Game(unsigned width, unsigned height);

	template <typename T>
	void setState();

	void update(float secs);
	void draw() const;

	inline bool isRunning() const { return mRunning; };
	inline void finish() { mRunning = false; };

	inline float getWidth() const { return mWidth; };
	inline float getHeight() const { return mHeight; };

protected:
	bool mRunning;
	TextureManager mTextureManager;
	SoundBuffer mSoundBuffer;

private:
	float mWidth;
	float mHeight;
	GameState::Ptr mState;
};


template <typename T>
void Game::setState()
{
	GameState::Ptr state(new T(GameState::Context(this, mTextureManager, mSoundBuffer)));
	mState = std::move(state);
}