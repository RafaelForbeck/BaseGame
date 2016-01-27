#pragma once

#include <Math/Matrix3.h>
#include <memory>

class Drawable
{
public:
	typedef std::unique_ptr<Drawable> Ptr;

	virtual void draw(const math::Matrix3 &matrix) const = 0;
};

