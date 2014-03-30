// GameObject.cpp

#include <iostream>
#include "GameObject.h"

#include "Sprite.h"
#include "Collider.h"

unsigned int GameObject::ms_object_count = 0;

unsigned int GameObject::GetCount() {
	return ms_object_count;
};

GameObject::GameObject() {
	ms_object_count++;
	m_x = 0.0f;
	m_y = 0.0f;
};

GameObject::GameObject(Sprite* _sprite, Collider* _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;

	ms_object_count++;
	m_x = 0.0f;
	m_y = 0.0f;
}

GameObject::~GameObject() {
	std::cout << "GameObject::~GameObject" << std::endl;
	ms_object_count--;
};

/*void GameObject::Update(float deltatime) {
	std::cout << "GameObject::Update" << std::endl;
};*/

//Player::Player() {
//	m_score = 0;
//};
//
//Player::~Player() {
//	std::cout << "Player::~Player" << std::endl;
//};
//
//void Player::Update(float deltatime) {
//	std::cout << "Player::Update" << std::endl;
//};
//
//Enemy::~Enemy() {
//	std::cout << "Enemy::~Enemy" << std::endl;
//};
//
//void Enemy::Update(float deltatime) {
//	std::cout << "Enemy::Update" << std::endl;
//};
//
//GameObjectManager::GameObjectManager() {
//};
//
//GameObjectManager::~GameObjectManager() {
//	auto it = m_objects.begin();
//	while(it != m_objects.end()) {
//		delete (*it);
//		++it;
//	};
//	m_objects.clear();
//};
//
//void GameObjectManager::Attach(GameObject *object) {
//	m_objects.push_back(object);
//};
//
//void GameObjectManager::UpdateAllGameObject(float deltatime) {
//	for(unsigned int i = 0; i < m_objects.size(); i++) {
//		m_objects[i]->Update(deltatime);
//	};
//};
