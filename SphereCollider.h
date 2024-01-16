#pragma once
#include "Transform.h"
#include "Collider.h"

class SphereCollider : public Collider
{
public:
	SphereCollider(Transform* transform, float radius);
	virtual ~SphereCollider() override;

	virtual bool CollidesWith(Collider& other) override;
	virtual bool CollidesWith(SphereCollider& other) override;

	float GetRadius() const;

private:
	float _radius = 1.0f;
};

