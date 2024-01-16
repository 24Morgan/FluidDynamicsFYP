#include "Collider.h"

Collider::Collider(Transform* transform) : _transform(transform)
{

}

Collider::~Collider()
{
	delete _transform;
}

Vector3 Collider::GetPosition() const
{
	return _transform->GetPosition();
}
