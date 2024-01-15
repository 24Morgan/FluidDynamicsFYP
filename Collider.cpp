#include "Collider.h"

Collider::Collider(Transform* transform) : _transform(transform)
{

}

Vector3 Collider::GetPosition() const
{
	return _transform->GetPosition();
}
