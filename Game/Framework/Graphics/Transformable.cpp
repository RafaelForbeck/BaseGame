#include "Transformable.h"
#include <Math/AffineTransform.h>

using namespace math;
using namespace math::rh;


Transformable::Transformable()
	: position(0.f, 0.f)
	, scale(1.f, 1.f)
	, rotation(0)
{
}


Matrix3 Transformable::calculateMatrix() const
{
	Matrix3 matrix = newAffineTranslation(position);
	matrix *= newAffineScale(scale.x, scale.y);
	matrix *= newAffineRotation(rotation);

	return matrix;
}