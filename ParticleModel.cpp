#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass)
{

}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float deltaTime)
{
	PhysicsModel::Update(deltaTime);
}
