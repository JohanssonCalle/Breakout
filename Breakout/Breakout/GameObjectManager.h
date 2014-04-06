//GameObjectManager.h

#pragma once

#include "GameObject.h"

#include <vector>

class DrawManager;
class CollisionManager;

class GameObjectManager {
public:
	GameObjectManager(CollisionManager* _collision_manager);
	~GameObjectManager();

	void Attach(GameObject *object);
	void UpdateAllGameObject(float deltatime);
	void DrawAllGameObjects(DrawManager* _draw_manager);

	void getScore();

	int m_score;

private:
	std::vector<GameObject*> m_objects;

	CollisionManager* m_collision_manager;
};