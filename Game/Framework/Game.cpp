#include "Game.h"


Game::Game(unsigned width, unsigned height)
	: mRunning(true)
	, mTextureManager()
	, mSoundBuffer()
	, mWidth(static_cast<float>(width))
	, mHeight(static_cast<float>(height))
{
}


void Game::update(float secs)
{
	mState->onUpdate(secs);
}


void Game::draw() const
{
	mState->onDraw();
}
