#include "../Resources.h"
#include "SplashState.h"
#include "PlayingState.h"
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

	mBackground = background.get();
	addChild(std::move(background));

	// carrega o som
	mContext.sounds->load(Sounds::IMPACT, "Assets/Sounds/impact.ogg");
}


void SplashState::update(float secs)
{
	if (mKeys[C2D2_ENTER].pressionado)
	{
		mContext.game->setState<PlayingState>();
		return;
	}

	mElapsedTime += secs;

	if (mElapsedTime >= 2)
	{
		mContext.game->setState<PlayingState>();
	}
}