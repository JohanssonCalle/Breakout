//PlayerObject.h

#pragma once

#include "Vector2.h"

#include "GameObject.h"

class DrawManager;
class Sprite;
class Collider;
class Mouse;

class PlayerObject : public GameObject
{
public:
	PlayerObject(Sprite* _sprite = nullptr, Collider* _collider = nullptr);
	~PlayerObject();

	void Update(float _deltatime);
	void Draw(DrawManager* _draw_manager);
	void getMouse(Mouse* _mouse);

	void setPosition(int _x, int _y);
	void setPosition(Vector2 _pos);

	void setDimensions(int _width, int _height);
	void setDimensions(Vector2 _dimensions);

	void getWindowDimensions(Vector2 _dimensions);

	Sprite* getSprite();
	Collider* getCollider();
	Vector2 getPosition();
	Vector2 getDimensions();

private:
	Sprite* m_sprite;
	Collider* m_collider;
	Mouse* m_mouse;

	Vector2 m_pos;
	Vector2 m_dimensions;

	Vector2 m_window_dimensions;
	Vector2 m_scale;
};