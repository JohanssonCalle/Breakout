//Ball.h

#pragma once

#include "GameObject.h"

#include "Vector2.h"
#include "SpriteManager.h"

#include <cmath>

class DrawManager;
class Sprite;
class Collider;
class Keyboard;

class Ball : public GameObject
{
public:
	Ball(Sprite* _sprite = nullptr, Collider* _collider = nullptr);
	~Ball();

	void Update(float _deltatime);
	void Draw(DrawManager* _draw_manager);

	void getKeyboard(Keyboard* _keyboard);
	float Random(float min, float max);

	void setPosition(int _x, int _y);
	void setPosition(Vector2 _pos);

	void setDirection(Vector2 _dir);

	Sprite* getSprite();
	Collider* getCollider();
	float getRadius();
	Vector2 getPosition();
	Vector2 getDirection();

private:
	Sprite* m_sprite;
	Collider* m_collider;
	Keyboard* m_keyboard;

	Vector2 m_dir;
	Vector2 m_pos;
	int m_size;
	float m_radius;
	
	float m_speed;
	float m_timer;
	bool m_move;
};