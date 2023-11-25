#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform) : PhysicsModel(transform)
{

}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float deltaTime)
{
	PhysicsModel::Update(deltaTime);
}
