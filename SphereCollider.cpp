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

	//Calculates the penetration distance - how much spheres overlap
	float penetrationDist = GetRadius() + other.GetRadius() - distance;

	//True only if spheres overlap
	if (penetrationDist > 0.0f)
	{
		//Calculates the penetration vector
		centreDist.Normalize();
		Vector3 penetrationVector = centreDist * penetrationDist;
		//Moves one sphere along the penetration vector by the penetration distance plus a gap
		Vector3 newPosition = GetPosition() - penetrationVector * (penetrationDist + 0.1f);
		_transform->SetPosition(newPosition);
		return true;
	}
	//Penetration distance lower than 0 meaning no overlap
	return false;
}

float SphereCollider::GetRadius() const
{
	return _radius;
}
