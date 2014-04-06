//CollisionManager.cpp

#include "CollisionManager.h"
#include "GameObject.h"

CollisionManager::CollisionManager(){}

void CollisionManager::Attach(GameObject* _gameobject)
{
	m_colliders.push_back(_gameobject->getCollider());
}

void CollisionManager::CheckCollision()
{
	for(int i = 0; i < m_colliders.size(); i++)
	{
		for(int k = 0; k < m_colliders.size(); i++)
		{
			m_colliders[i]->m_collided = m_colliders[i]->Overlap(*m_colliders[k], m_colliders[k]->getExtension());
		}
	}
}

void CollisionManager::Cleanup()
{
	auto it = m_colliders.begin();
	while(it != m_colliders.end()) {
		delete (*it);
		++it;
	};
	m_colliders.clear();
}