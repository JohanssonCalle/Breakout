//GameObjectManager.h

#pragma once

#include "GameObject.h"

#include <vector>

class DrawManager;

class GameObjectManager {
public:
	GameObjectManager();
	~GameObjectManager();

	void Attach(GameObject *object);
	void UpdateAllGameObject(float deltatime);
	void DrawAllGameObjects(DrawManager* _draw_manager);

private:
	std::vector<GameObject*> m_objects;
};