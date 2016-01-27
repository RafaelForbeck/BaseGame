#pragma once

#include "../Graphics/Transformable.h"
#include <Math/Vector2.h>
#include <memory>

class Body
{
public:
	typedef std::unique_ptr<Body> Ptr;

	Body(Transformable* owner, float mass = 1.f);

	void setMass(float mass);

	void applyForce(float x, float y);
	void applyForce(math::Vector2 force);

	void applyImpulse(float x, float y);
	void applyImpulse(math::Vector2 impulse);

	void setMaxSpeed(float speed);

	inline float getSpeed() const { return mMomentum.size(); };
	inline float getSpeedSqr() const { return mMomentum.sizeSqr(); };

	void update(float secs);

private:
	Transformable* mOwner;

	float mMass;
	float mMaxSpeed;
	float mMaxSpeedSqr;

	math::Vector2 mForces;
	math::Vector2 mImpulse;

	math::Vector2 mMomentum;
};
