#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass)
{

}

ParticleModel::~ParticleModel()
{

}

void ParticleModel::Update(float deltaTime)
{
	//Viscosity slightly decreases velocity each tick to mimic a viscous fluid
	_velocity *= _viscosity;
	PhysicsModel::Update(deltaTime);
}
