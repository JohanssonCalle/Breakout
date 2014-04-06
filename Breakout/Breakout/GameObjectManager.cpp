//GameObjectManager.cpp

#include "GameObjectManager.h"

#include "DrawManager.h"
#include "CollisionManager.h"

GameObjectManager::GameObjectManager(CollisionManager* _collision_manager) 
{
	m_collision_manager = _collision_manager;
}

GameObjectManager::~GameObjectManager() {
	auto it = m_objects.begin();
	while(it != m_objects.end()) {
		delete (*it);
		++it;
	};
	m_objects.clear();

	delete m_collision_manager;
	m_collision_manager = nullptr;
};

void GameObjectManager::Attach(GameObject *object) {
	m_objects.push_back(object);

	m_collision_manager->Attach(object->getCollider());
};

void GameObjectManager::UpdateAllGameObject(float deltatime) {
	for(unsigned int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->Update(deltatime);
	};

	m_collision_manager->CheckCollision();
};

void GameObjectManager::DrawAllGameObjects(DrawManager* _draw_manager)
{
	for(int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i]->Draw(_draw_manager);
	}
}