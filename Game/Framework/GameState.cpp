#include "GameState.h"
#include "Game.h"


GameState::GameState(Context context)
	: mContext(context)
	, mSceneGraph()
{
	mSceneGraph.position = math::Vector2(
		mContext.game->getWidth() / 2,
		mContext.game->getHeight() / 2);

	mKeys = C2D2_PegaTeclas();
}


void GameState::onUpdate(float secs)
{
	mSceneGraph.onUpdate(secs);
	update(secs);
}


void GameState::onDraw() const
{
	mSceneGraph.onDraw(math::Matrix3::newIdentity());
	draw();
}


void GameState::update(float secs) {}
void GameState::draw() const {}


void GameState::addChild(SceneNode::Ptr node)
{
	mSceneGraph.addChild(std::move(node));
}