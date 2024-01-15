#include "SphereCollider.h"

SphereCollider::SphereCollider(Transform* transform, float radius) : Collider(transform), _radius(radius)
{

}

bool SphereCollider::CollidesWith(Collider& other)
{
	return other.CollidesWith(*this);
}

bool SphereCollider::CollidesWith(SphereCollider& other)
{
	return false;
}

float SphereCollider::GetRadius() const
{
	return 0.0f;
}
