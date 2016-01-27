#include "Game/Entities/Ship.h"
#include "Game/Resources.h"
#include "Framework/Game.h"
#include "Framework/Graphics/Sprite.h"
#include "PlayingState.h"
#include <Math/Vector2.h>

using namespace math;


PlayingState::PlayingState(Context context)
	: GameState(context)
{
	mContext.textures->load(Textures::SHIP, "Assets/Textures/ship.png");
	unsigned shipTexture = mContext.textures->get(Textures::SHIP);

	SceneNode::Ptr ship(new Ship(shipTexture, 1, 1, 10000, 10, 1, 1000));

	mShip = dynamic_cast<Ship*>(ship.get());
	addChild(std::move(ship));
}


void PlayingState::update(float secs)
{
	if (mKeys[C2D2_CIMA].ativo)
		mShip->throttle();

	if (mKeys[C2D2_ESQUERDA].ativo)
		mShip->turnLeft(secs);

	if (mKeys[C2D2_DIREITA].ativo)
		mShip->turnRight(secs);

	if (mKeys[C2D2_ESPACO].ativo)
		mShip->position.set(0.f, 0.f);

	if (mShip->position.x > mContext.game->getWidth() / 2.f) {
		mShip->position.x -= mContext.game->getWidth();
	}
	else if (mShip->position.x < -mContext.game->getWidth() / 2.f) {
		mShip->position.x += mContext.game->getWidth();
	}

	if (mShip->position.y > mContext.game->getHeight() / 2.f) {
		mShip->position.y -= mContext.game->getHeight();
	}
	else if (mShip->position.y < -mContext.game->getHeight() / 2.f) {
		mShip->position.y += mContext.game->getHeight();
	}
}