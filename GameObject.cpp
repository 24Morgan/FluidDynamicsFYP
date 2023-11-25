#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, Transform* transform) : _type(type), _appearance(appearance), _transform(transform)
{
	_particleModel = new ParticleModel(transform);
}

GameObject::~GameObject()
{
	delete _appearance;
	delete _transform;
	delete _particleModel;
}

void GameObject::Update(float t)
{
	_particleModel->Update(t);
	_transform->Update();
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	_appearance->Draw(pImmediateContext);
}
