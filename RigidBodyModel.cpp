#include "RigidBodyModel.h"

RigidBodyModel::RigidBodyModel(Transform* transform, float mass) : PhysicsModel(transform, mass)
{

}

RigidBodyModel::~RigidBodyModel()
{

}

void RigidBodyModel::Update(float deltaTime)
{
	PhysicsModel::Update(deltaTime);
}
