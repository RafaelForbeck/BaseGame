#pragma once

#include <map>

class TextureManager
{
public:
	TextureManager();

	void load(int textureID, const char *filename);
	unsigned get(int textureID);

private:
	std::map<int, unsigned> mTextures;
};

