#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
public:
	ParticleModel(Transform* transform);
	virtual ~ParticleModel() override;

	virtual void Update(float deltaTime) override;
};

