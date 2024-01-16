#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(Transform* transform);	//Needs a
	virtual ~AABBCollider() override;

	virtual bool CollidesWith(Collider& other) override;
	virtual bool CollidesWith(SphereCollider& other) override;


private:

};

