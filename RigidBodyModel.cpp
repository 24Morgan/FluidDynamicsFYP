#include "RigidBodyModel.h"

RigidBodyModel::RigidBodyModel(Transform* transform, float mass) : PhysicsModel(transform, mass)
{

}

RigidBodyModel::~RigidBodyModel()
{

}

void RigidBodyModel::Update(float deltaTime)
{
	//Ensures objects of RigidBodyModel do not move
	_velocity = Vector3(0, 0, 0);
	//PhysicsModel::Update(deltaTime);
}
