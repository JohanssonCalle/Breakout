// GameObject.h

#pragma once

#include "Vector2.h"

class Sprite;
class Collider;
class DrawManager;

class GameObject {
	//friend class CollisionManager;

public:
	GameObject(Sprite* _sprite = nullptr, Collider* _collider = nullptr);

	virtual void Update(float deltatime) = 0;
	virtual void Draw(DrawManager* _draw_manager) = 0;

	void giveWindowDimensions(Vector2 _dimensions);
	void setID(int _id);

	bool hasSprite();
	Sprite* getSprite();
	bool hasCollider();
	Collider* getCollider();

protected:
	Vector2 m_scale;
	Vector2 m_window_dimensions;

	static unsigned int ID;
	float m_x;
	float m_y;

	Sprite* m_sprite;
	Collider* m_collider;
};