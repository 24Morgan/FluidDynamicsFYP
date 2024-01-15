#pragma once
#include "Transform.h"

class PhysicsModel
{
public:
	PhysicsModel(Transform* transform, float mass);
	virtual ~PhysicsModel();

	virtual void Update(float deltaTime) = 0;

	virtual void SetVelocity(Vector3 newVelocity);
	virtual Vector3 GetVelocity();

	virtual void SetAcceleration(Vector3 newAcceleration);
	virtual Vector3 GetAcceleration();

	//Forces
	virtual Vector3 GravityForce();
	virtual void SimulateGravity(bool gravity) { _simulateGravity = gravity; }

	void AddForce(Vector3 force);

private:


protected:
	Transform* _transform;

	//Movement
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;	//Tracks total force applied to object
	Vector3 _gravity = Vector3(0.0f, -9.81f, 0.0f);	//Applies gravity in negative y
	bool _simulateGravity = false;

	//Physical properties
	float _mass = 1.0f;
};

