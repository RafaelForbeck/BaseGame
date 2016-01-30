#pragma once

#include "Framework/GameState.h"

class StoryState : public GameState
{
public:
	StoryState(Context);

	virtual void update(float secs);

private:
};

