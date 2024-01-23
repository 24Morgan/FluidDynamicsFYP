#include "Collider.h"

Collider::Collider(Transform* transform) : _transform(transform)
{

}

Collider::~Collider()
{
	
}

Vector3 Collider::GetPosition() const
{
	return _transform->GetPosition();
}
