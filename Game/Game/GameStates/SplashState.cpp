#include "../Resources.h"
#include "SplashState.h"
#include "TitleState.h"
#include "Framework/Game.h"
#include "Framework/Graphics/Sprite.h"

using namespace math;


SplashState::SplashState(Context context)
	: GameState(context)
{
	// adiciona a logo
	mContext.textures->load(Textures::SPLASH_SCREEN, "Assets/Textures/SplashScreen.png");
	SceneNode::Ptr background(new SceneNode());
	background->setView(Drawable::Ptr(new Sprite(mContext.textures->get(Textures::SPLASH_SCREEN))));
	addChild(std::move(background));
}


void SplashState::update(float secs)
{
	mElapsedTime += secs;

	if (mElapsedTime >= 2)
	{
		mContext.game->setState<TitleState>();
	}
}