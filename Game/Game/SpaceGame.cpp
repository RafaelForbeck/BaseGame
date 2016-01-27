#include "SpaceGame.h"
#include "GameStates/PlayingState.h"
#include "GameStates/SplashState.h"


SpaceGame::SpaceGame(unsigned width, unsigned height)
	: Game(width, height)
{
	setState<SplashState>();
}

