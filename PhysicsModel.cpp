#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform, float mass) : _transform(transform), _mass(mass)
{
	
}

PhysicsModel::~PhysicsModel()
{
	delete _transform;
	delete _collider;
}

void PhysicsModel::Update(float deltaTime)
{
	//May need an if check in the future as to not affect all objects
	if (_simulateGravity)
	_netForce += GravityForce();

	//F = M*A
	_acceleration += _netForce / _mass;
	_velocity += _acceleration * deltaTime;

	Vector3 position = _transform->GetPosition();
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	//Must be reset and recalculated each frame
	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
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

Vector3 PhysicsModel::GravityForce() 
{ 
	return _gravity * _mass; 
}

void PhysicsModel::SimulateGravity(bool gravity)
{
	_simulateGravity = gravity;
}

void PhysicsModel::AddForce(Vector3 force)
{
	_netForce += force;
}

bool PhysicsModel::IsCollideable() const
{
	return _collider != nullptr;
}

Collider* PhysicsModel::GetCollider() const
{
	return _collider;
}

void PhysicsModel::SetCollider(Collider* collider)
{
	_collider = collider;
}
