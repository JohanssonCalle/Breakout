//PlayerObject.cpp

#include "PlayerObject.h"

#include "Sprite.h"
#include "DrawManager.h"

PlayerObject::PlayerObject(Sprite* _sprite, Collider* _collider)
	: GameObject(_sprite, _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;
}

PlayerObject::PlayerObject(Sprite* _sprite, Collider* _collider, int _x, int _y)
	: GameObject(_sprite, _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;
	m_pos = Vector2(_x, _y);
}

PlayerObject::PlayerObject(Sprite* _sprite, Collider* _collider, int _x, int _y, int _width, int _height)
	: GameObject(_sprite, _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;
	m_pos = Vector2(_x, _y);
	m_dimensions = Vector2(_width, _height);
}

void PlayerObject::setPosition(int _x, int _y)
{
	m_pos = Vector2(_x, _y);
}

void PlayerObject::setPosition(Vector2 _pos)
{
	m_pos = _pos;
}

void PlayerObject::setDimensions(int _width, int _height)
{
	m_dimensions = Vector2(_width, _height);
}

void PlayerObject::setDimensions(Vector2 _dimensions)
{
	m_dimensions = _dimensions;
}

void PlayerObject::Update(float _deltatime)
{

}

void PlayerObject::Draw()
{

}

Sprite* PlayerObject::getSprite(){return m_sprite;}

Collider* PlayerObject::getCollider(){return m_collider;}

Vector2 PlayerObject::getPosition(){return m_pos;}

Vector2 PlayerObject::getDimensions(){return m_dimensions;}