#pragma once
#include "Transform.h"

class PhysicsModel
{
public:
	PhysicsModel(Transform* transform);
	~PhysicsModel();

	void Update(float deltaTime);

	void SetVelocity(Vector3 newVelocity);
	Vector3 GetVelocity();

	void SetAcceleration(Vector3 newAcceleration);
	Vector3 GetAcceleration();

private:


protected:
	Transform* _transform;

	//Movement
	Vector3 _velocity;
	Vector3 _acceleration;
};

