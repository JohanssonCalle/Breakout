//CollisionManager.h

#pragma once

#include "Vector2.h"
#include <cmath>
#include <vector>

class Collider;

class CollisionManager
{
	friend class GameObjectManager;

public:
	CollisionManager();
	void Cleanup();

	void Attach(Collider* _collider);

	void CheckCollision();

private:
	std::vector<Collider*> m_colliders;
};