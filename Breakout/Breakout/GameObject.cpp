// GameObject.cpp

#include <iostream>
#include "GameObject.h"

#include "Sprite.h"
#include "Collider.h"

unsigned int GameObject::ID = 0;

GameObject::GameObject(Sprite* _sprite, Collider* _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;
}

void GameObject::giveWindowDimensions(Vector2 _dimensions)
{
	m_window_dimensions = _dimensions;

	m_scale.m_x = (float)m_window_dimensions.m_x/1280.f;
	m_scale.m_y = (float)m_window_dimensions.m_y/720.f;
}

void GameObject::setID(int _id)
{
	ID = _id;
}

bool GameObject::hasSprite(){return m_sprite != nullptr;}
Sprite* GameObject::getSprite(){return m_sprite;}
bool GameObject::hasCollider(){return m_collider != nullptr;}
Collider* GameObject::getCollider(){return m_collider;}