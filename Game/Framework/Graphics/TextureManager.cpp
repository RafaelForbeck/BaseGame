#include "TextureManager.h"
#include <c2d2/chien2d2.h>


TextureManager::TextureManager()
{
}


void TextureManager::load(int textureID, const char *filename)
{
	unsigned sprite = C2D2_CarregaSpriteSet(filename, 0, 0);
	mTextures[textureID] = sprite;
}


unsigned TextureManager::get(int textureID)
{
	return mTextures[textureID];
}