#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
public:
	ParticleModel(Transform* transform, float mass = 1.0f);
	virtual ~ParticleModel() override;

	virtual void Update(float deltaTime) override;

private:
	float _viscosity = 0.99f;
};

