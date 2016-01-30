#pragma once

#include "Framework/GameState.h"

class TitleState : public GameState
{
public:
	TitleState(Context);

	virtual void update(float secs);

private:
};

