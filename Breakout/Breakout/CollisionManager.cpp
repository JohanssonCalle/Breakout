//CollisionManager.cpp

#include "CollisionManager.h"

#include "Collider.h"

CollisionManager::CollisionManager(){}

void CollisionManager::Attach(Collider* _collider)
{
	m_colliders.push_back(_collider);
}

void CollisionManager::CheckCollision()
{
	for(int i = 0; i < m_colliders.size(); i++)
	{
		for(int k = 0; k < m_colliders.size(); k++)
		{
			m_colliders[i]->m_collided = m_colliders[i]->Overlap(*m_colliders[k], m_colliders[k]->m_extension);
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