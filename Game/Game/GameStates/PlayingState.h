#pragma once

#include "Framework/GameState.h"
#include "Game/Entities/Ship.h"

class PlayingState : public GameState
{
public:
	PlayingState(Context);

	virtual void update(float secs);

private:
	Ship* mShip;
};

