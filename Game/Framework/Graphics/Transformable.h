#pragma once

#include <Math/Vector2.h>
#include <Math/Matrix3.h>

class Transformable
{
public:
	Transformable();

	math::Matrix3 calculateMatrix() const;

public:
	math::Vector2 position;
	math::Vector2 scale;
	float rotation;

};

