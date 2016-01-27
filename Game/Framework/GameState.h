#pragma once

#include "Audio/SoundBuffer.h"
#include "Graphics/TextureManager.h"
#include "Scene/SceneNode.h"
#include <c2d2/chien2d2.h>
#include <memory>

class Game;

class GameState
{
public:
	typedef std::unique_ptr<GameState> Ptr;

	struct Context
	{
		Context(Game* game, TextureManager& textures, SoundBuffer& sounds)
			: game(game)
			, textures(&textures)
			, sounds(&sounds) {};
		
		Game* game;
		TextureManager* textures;
		SoundBuffer* sounds;
	};

	GameState(Context);

	void onUpdate(float secs);
	void onDraw() const;

	virtual void update(float secs);
	virtual void draw() const;

protected:
	void addChild(SceneNode::Ptr);

protected:
	Context mContext;
	C2D2_Botao* mKeys;

private:
	SceneNode mSceneGraph;
};

