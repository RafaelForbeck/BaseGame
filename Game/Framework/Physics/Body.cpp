#include "Body.h"

using namespace math;


Body::Body(Transformable* owner, float mass)
	: mOwner(owner)
	, mMaxSpeed(FLT_MAX)
	, mMaxSpeedSqr(FLT_MAX)
{
	setMass(mass);
}


void Body::setMass(float mass)
{
	mMass = mass > 0 ? mass : FLT_EPSILON;
}


void Body::applyForce(float x, float y)
{
	mForces += Vector2(x, y);
}


void Body::applyForce(Vector2 force)
{
	mForces += force;
}


void Body::applyImpulse(float x, float y)
{
	mImpulse += Vector2(x, y);
}


void Body::applyImpulse(Vector2 impulse)
{
	mImpulse += impulse;
}


void Body::setMaxSpeed(float speed)
{
	mMaxSpeed = speed;
	mMaxSpeedSqr = speed * speed;
}


void Body::update(float secs)
{
	mMomentum += mImpulse / mMass;

	Vector2 acceleration = (mForces / mMass) * secs;
	Vector2 velocity = mMomentum + acceleration / 2.f;
	if (velocity.sizeSqr() > mMaxSpeedSqr)
	{
		velocity.resize(mMaxSpeed);
		mMomentum.set(velocity);
	}

	mOwner->position += velocity * secs;
	mMomentum += acceleration;

	mImpulse = mForces = Vector2();
}