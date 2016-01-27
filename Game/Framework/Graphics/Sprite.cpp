#include "Sprite.h"
#include <c2d2/chien2d2.h>
#include <Math/AffineTransform.h>

using namespace math;
using namespace math::rh;


Sprite::Sprite(unsigned texture, float rotation)
	: mTexture(texture)
	, mRotation(rotation)
{
	C2D2_DimensoesSprite(mTexture, &mWidth, &mHeight);
}


void Sprite::draw(const Matrix3 &matrix) const
{
	float hw = mWidth / 2.f, hh = mHeight / 2.f;
	Vector2 vertices[4] = {Vector2(-hw, -hh), Vector2(hw, -hh), Vector2(hw, hh), Vector2(-hw, hh)};

	Matrix3 myMatrix = matrix;
	if (mRotation != 0.f)
		myMatrix *= newAffineRotation(mRotation);

	int x[4], y[4];
	for (int i = 0; i < 4; i++)
	{
		Vector2 vertex = transform(myMatrix, vertices[i]);
		x[i] = static_cast<int>(vertex.x);
		y[i] = static_cast<int>(vertex.y);
	}

	C2D2_DesenhaSpriteEfeito(mTexture, 0, x, y, 255, 255, 255, 255);
}