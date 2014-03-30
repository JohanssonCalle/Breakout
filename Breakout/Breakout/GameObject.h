// GameObject.h

#pragma once

#include <vector>

class Sprite;
class Collider;

class GameObject {
	//friend class CollisionManager;

public:
	GameObject();
	GameObject(Sprite* _sprite, Collider* _collider);
	virtual ~GameObject();

	virtual void Update(float deltatime) = 0;

	static unsigned int GetCount();

protected:
	static unsigned int ms_object_count;
	float m_x;
	float m_y;

	Sprite* m_sprite;
	Collider* m_collider;
};


//class Player : public GameObject {
//public:
//	Player();
//	~Player();
//
//	void Update(float deltatime);
//
//protected:
//	int m_score;
//};
//
//class Enemy : public GameObject {
//public:
//	~Enemy();
//
//	void Update(float deltatime);
//};
//
//class GameObjectManager {
//public:
//	GameObjectManager();
//	~GameObjectManager();
//
//	void Attach(GameObject *object);
//	void UpdateAllGameObject(float deltatime);
//
//private:
//	std::vector<GameObject*> m_objects;
//};