#include "Ship.h"
#include "Framework\Graphics\Sprite.h"

using namespace math;


Ship::Ship(float health, float energy, float thrust, float torque, float mass, float maxSpeed)
	: mHealth(health)
	, mEnergy(energy)
	, mThrust(thrust)
	, mTorque(torque)
{
	enablePhysics();
	mBody->setMass(mass);
	mBody->setMaxSpeed(maxSpeed);
}

Ship::Ship(unsigned texture, float health, float energy, float thrust, float torque, float mass, float maxSpeed)
	: Ship(health, energy, thrust, torque, mass, maxSpeed)
{
	setView(Drawable::Ptr(new Sprite(texture, math::PI / 2.f)));
}

void Ship::throttle()
{
	mBody->applyForce(Vector2::newBySizeAngle(mThrust, rotation));
}


void Ship::turnLeft(float secs)
{
	rotation -= mTorque * secs;
}


void Ship::turnRight(float secs)
{
	rotation += mTorque * secs;
}
