#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform) : _transform(transform)
{

}

PhysicsModel::~PhysicsModel()
{
	_transform = nullptr;
}

void PhysicsModel::Update(float deltaTime)
{
	_velocity += _acceleration * deltaTime;

	Vector3 position = _transform->GetPosition();
	position += _velocity * deltaTime;
	_transform->SetPosition(position);
}

void PhysicsModel::SetVelocity(Vector3 newVelocity)
{
	_velocity = newVelocity;
}

Vector3 PhysicsModel::GetVelocity()
{
	return _velocity;
}

void PhysicsModel::SetAcceleration(Vector3 newAcceleration)
{
	_acceleration = newAcceleration;
}

Vector3 PhysicsModel::GetAcceleration()
{
	return _acceleration;
}
