#pragma once
#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
public:
	RigidBodyModel(Transform* transform, float mass = 1.0f);
	virtual ~RigidBodyModel() override;

	virtual void Update(float deltaTime) override;
};

