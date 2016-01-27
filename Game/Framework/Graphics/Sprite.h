#pragma once

#include "Drawable.h"

class Sprite : public Drawable
{
public:
	Sprite(unsigned texture, float rotation = 0.f);

	virtual void draw(const math::Matrix3 &matrix) const;

private:
	int mTexture;
	float mRotation;
	int mWidth;
	int mHeight;
};

