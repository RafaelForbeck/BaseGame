#pragma once

#include "Framework/Scene/SceneNode.h"
#include <functional>

class Ship : public SceneNode
{
public:
	Ship(float health, float energy, float thrust, float torque, float mass, float maxSpeed);
	Ship(unsigned texture, float health, float energy, float thrust, float torque, float mass, float maxSpeed);


	void throttle();
	void turnLeft(float secs);
	void turnRight(float secs);

	void fireCannon();

private:
	float mHealth;
	float mEnergy;

	float mThrust;
	float mTorque;
};

