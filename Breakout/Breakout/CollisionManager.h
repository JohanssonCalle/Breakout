//CollisionManager.h

#pragma once

#include "Collider.h"

#include "Vector2.h"
#include <cmath>
#include <map>

class GameObject;

class CollisionManager
{
	friend class GameObjectManager;

public:
	CollisionManager();

	void Attach(GameObject* _gameobject);

	void CheckCollision();

private:

};