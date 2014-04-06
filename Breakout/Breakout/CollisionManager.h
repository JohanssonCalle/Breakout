//CollisionManager.h

#pragma once

#include "Collider.h"

#include "Vector2.h"
#include <cmath>
#include <vector>

class GameObject;

class CollisionManager
{
	friend class GameObjectManager;

public:
	CollisionManager();
	void Cleanup();

	void Attach(GameObject* _gameobject);

	void CheckCollision();

private:
	std::vector<Collider*> m_colliders;
};