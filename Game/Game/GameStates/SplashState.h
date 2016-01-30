#pragma once

#include "Framework/GameState.h"

class SplashState : public GameState
{
public:
	SplashState(Context);

	virtual void update(float secs);

private:
	float mElapsedTime;
};

