#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, Transform* transform) : _type(type), _appearance(appearance), _transform(transform)
{
	_physicsModel = new PhysicsModel(transform);
}

GameObject::~GameObject()
{
	_appearance = nullptr;
	_transform = nullptr;
	_physicsModel = nullptr;
}

void GameObject::Update(float t)
{
	_physicsModel->Update(t);
	_transform->Update();
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	_appearance->Draw(pImmediateContext);
}
