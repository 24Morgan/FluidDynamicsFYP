#pragma once
#include "Transform.h"

class ParticleCollider;

//Parent class to manage different types of collisions between objects
class Collider abstract
{
public:
	Collider(Transform* transform);
	virtual ~Collider();

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(ParticleCollider& other) = 0;

	virtual Vector3 GetPosition() const;

protected:
	Transform* _transform;

};

