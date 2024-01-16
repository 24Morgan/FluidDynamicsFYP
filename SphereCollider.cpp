#include "SphereCollider.h"

SphereCollider::SphereCollider(Transform* transform, float radius) : Collider(transform), _radius(radius)
{

}

SphereCollider::~SphereCollider()
{

}

bool SphereCollider::CollidesWith(Collider& other)
{
	return other.CollidesWith(*this);
}

bool SphereCollider::CollidesWith(SphereCollider& other)
{
	//Calculate the vector between the centre of both spheres
	Vector3 centreDist = other.GetPosition() - GetPosition();

	//Calculates length of vector between spheres
	float distance = centreDist.Magnitude();
	
	//Returns true if combined radii is greater than distance meaning they have overlapped
	return distance < (GetRadius() + other.GetRadius());
}

float SphereCollider::GetRadius() const
{
	return _radius;
}
