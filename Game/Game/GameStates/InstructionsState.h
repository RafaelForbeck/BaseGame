#pragma once

#include "Framework/GameState.h"

class InstructionsState : public GameState
{
public:
	InstructionsState(Context);

	virtual void update(float secs);

private:
};

