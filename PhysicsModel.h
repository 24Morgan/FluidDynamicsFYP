#pragma once
#include "Transform.h"

class PhysicsModel
{
public:
	PhysicsModel(Transform* transform);
	virtual ~PhysicsModel();

	virtual void Update(float deltaTime) = 0;

	virtual void SetVelocity(Vector3 newVelocity);
	virtual Vector3 GetVelocity();

	virtual void SetAcceleration(Vector3 newAcceleration);
	virtual Vector3 GetAcceleration();

private:


protected:
	Transform* _transform;

	//Movement
	Vector3 _velocity;
	Vector3 _acceleration;
};

