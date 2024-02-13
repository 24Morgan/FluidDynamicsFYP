#pragma once

#include <directxmath.h>
#include <d3d11_4.h>
#include <string>
#include "Structures.h"
#include "Vector3.h"
#include "Transform.h"
#include "Appearance.h"
#include "PhysicsModel.h"
#include "ParticleModel.h"
#include "RigidBodyModel.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Appearance* appearance, Transform* transform, PhysicsModel* physics);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform() const { return _transform; }
	Appearance* GetAppearance() const { return _appearance; }
	PhysicsModel* GetPhysicsModel() const { return _physicsModel; }		//_physicsModel may need to be swapped

	void Update(float t);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:
	string _type;

	Transform* _transform;
	Appearance* _appearance;

	PhysicsModel* _physicsModel;

};

