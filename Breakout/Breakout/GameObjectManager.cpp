//GameObjectManager.cpp

#include "GameObjectManager.h"

#include "DrawManager.h"

GameObjectManager::GameObjectManager() {
};

GameObjectManager::~GameObjectManager() {
	auto it = m_objects.begin();
	while(it != m_objects.end()) {
		delete (*it);
		++it;
	};
	m_objects.clear();
};

void GameObjectManager::Attach(GameObject *object) {
	m_objects.push_back(object);
};

void GameObjectManager::UpdateAllGameObject(float deltatime) {
	for(unsigned int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->Update(deltatime);
	};
};

void GameObjectManager::DrawAllGameObjects(DrawManager* _draw_manager)
{
	for(int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i]->Draw(_draw_manager);
	}
}