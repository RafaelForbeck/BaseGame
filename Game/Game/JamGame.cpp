#include "JamGame.h"
#include "GameStates/PlayingState.h"
#include "GameStates/SplashState.h"


JamGame::JamGame(unsigned width, unsigned height)
	: Game(width, height)
{
	setState<SplashState>();
}
