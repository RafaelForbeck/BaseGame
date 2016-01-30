#pragma once

#include "Framework/GameState.h"

class GameoverState : public GameState
{
public:
	GameoverState(Context);

	virtual void update(float secs);

private:
};

