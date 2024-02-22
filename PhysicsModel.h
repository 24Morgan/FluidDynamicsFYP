#pragma once
#include "Transform.h"
#include "Collider.h"
#include "ParticleCollider.h"

class PhysicsModel abstract
{
public:
	PhysicsModel(Transform* transform, float mass);
	virtual ~PhysicsModel();

	virtual void Update(float deltaTime) = 0;

	virtual void SetVelocity(Vector3 newVelocity);
	virtual Vector3 GetVelocity();

	virtual void SetAcceleration(Vector3 newAcceleration);
	virtual Vector3 GetAcceleration();

	virtual float GetMass();

	//Forces
	virtual Vector3 GravityForce();
	virtual void SimulateGravity(bool gravity);
	virtual void SimulateGravity();

	virtual void AddForce(Vector3 force);

	//Collision handling
	virtual bool IsCollideable() const;
	virtual Collider* GetCollider() const;
	virtual void SetCollider(Collider* collider);
	virtual void ApplyImpulse(Vector3 impulse);

private:


protected:
	Transform* _transform;
	Collider* _collider = nullptr;

	//Movement
	Vector3 _velocity;
	Vector3 _acceleration;
	Vector3 _netForce;	//Tracks total force applied to object
	Vector3 _gravity = Vector3(0.0f, -3.00f, 0.0f);	//Applies gravity in negative y - dampened to stop particles moving too quick
	bool _simulateGravity = false;

	//Physical properties
	float _mass = 1.0f;
};

