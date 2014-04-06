//Brick.h

#pragma once

#include "GameObject.h"
#include "Vector2.h"

class DrawManager;
class Sprite;
class Collider;

class Brick : public GameObject
{
public:
	Brick(Sprite* _sprite = nullptr, Collider* _collider = nullptr);
	~Brick();

	void Update(float _deltatime);
	void Draw(DrawManager* _draw_manager);

	void setPosition(int _x, int _y);
	void setPosition(Vector2 _pos);

	void setDimension(int _width, int _height);
	void setDimension(Vector2 _dimensions);

	Vector2 getPosition();
	Vector2 getDimensions();

	void Destroy();

private:
	Sprite* m_sprite;
	Collider* m_collider;
	Vector2 m_pos;
	Vector2 m_dimensions;
};