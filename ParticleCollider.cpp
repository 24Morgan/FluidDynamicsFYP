#include "ParticleCollider.h"

ParticleCollider::ParticleCollider(Transform* transform, float radius) : Collider(transform), _radius(radius)
{

}

ParticleCollider::~ParticleCollider()
{

}

bool ParticleCollider::CollidesWith(Collider& other)
{
	return other.CollidesWith(*this);
}

bool ParticleCollider::CollidesWith(ParticleCollider& other)
{
	//Calculate the vector between the centre of both particles
	Vector3 centreDist = other.GetPosition() - GetPosition();

	//Calculates length of vector between particles
	float distance = centreDist.Magnitude();

	//Calculates the penetration distance - how much particles overlap
	float penetrationDist = GetRadius() + other.GetRadius() - distance;

	//True only if particles overlap
	if (penetrationDist > 0.0f)
	{
		//Calculates the penetration vector
		centreDist.Normalize();
		Vector3 penetrationVector = centreDist * penetrationDist;
		//Moves one particle along the penetration vector by the penetration distance plus a gap
		Vector3 newPosition = GetPosition() - penetrationVector * (penetrationDist + 0.1f);
		_transform->SetPosition(newPosition);
		return true;
	}
	//Penetration distance lower than 0 meaning no overlap
	return false;
}

float ParticleCollider::GetRadius() const
{
	return _radius;
}
