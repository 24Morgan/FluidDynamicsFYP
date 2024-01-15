#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance, Transform* transform, PhysicsModel* physics) : _type(type), _appearance(appearance), _transform(transform), _physicsModel(physics)
{

}

GameObject::~GameObject()
{
	delete _appearance;
	delete _transform;
	delete _physicsModel;
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
