#pragma once
#include "Transform.h"
#include "Collider.h"

class ParticleCollider : public Collider
{
public:
	ParticleCollider(Transform* transform, float radius);
	virtual ~ParticleCollider() override;

	virtual bool CollidesWith(Collider& other) override;
	virtual bool CollidesWith(ParticleCollider& other) override;

	float GetRadius() const;

private:
	float _radius = 1.0f;
};

