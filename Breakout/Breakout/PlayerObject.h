//PlayerObject.h

#pragma once

#include "Vector2.h"

#include "GameObject.h"

class Sprite;
class Collider;

class PlayerObject : public GameObject
{
public:
	PlayerObject(Sprite* _sprite, Collider* _collider);
	PlayerObject(Sprite* _sprite, Collider* _collider, int _x, int _y);
	PlayerObject(Sprite* _sprite, Collider* _collider, int _x, int _y, int _width, int _height);

	void Update(float _deltatime);
	void Draw();

	void setPosition(int _x, int _y);
	void setPosition(Vector2 _pos);

	void setDimensions(int _width, int _height);
	void setDimensions(Vector2 _dimensions);

	Sprite* getSprite();
	Collider* getCollider();
	Vector2 getPosition();
	Vector2 getDimensions();

private:
	Sprite* m_sprite;
	Collider* m_collider;
	Vector2 m_pos;
	Vector2 m_dimensions;
};