#pragma once
#include "Transform.h"

class SphereCollider;

//Parent class to manage different types of collisions between objects
class Collider abstract
{
public:
	Collider(Transform* transform);
	virtual ~Collider();

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;

	Vector3 GetPosition() const;

protected:
	Transform* _transform;

};

