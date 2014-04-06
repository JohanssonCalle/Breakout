//PlayerObject.cpp

#include "PlayerObject.h"

#include "Sprite.h"
#include "Collider.h"
#include "DrawManager.h"

#include "Input.h"

PlayerObject::PlayerObject(Sprite* _sprite, Collider* _collider)
	: GameObject(_sprite, _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;

	m_score = 0;
}

PlayerObject::~PlayerObject()
{
	delete m_sprite; m_sprite = nullptr;
	delete m_collider; m_collider = nullptr;
}

void PlayerObject::getMouse(Mouse* _mouse)
{
	m_mouse = _mouse;
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
	m_pos.m_x = m_mouse->GetX() - m_collider->m_extension.m_x/2;
	
	if(m_pos.m_x < 80*m_scale.m_x)
	{
		m_pos.m_x = 80*m_scale.m_x;
	}
	if(m_pos.m_x > m_window_dimensions.m_x - 80*m_scale.m_x - m_collider->m_extension.m_x)
	{
		m_pos.m_x = m_window_dimensions.m_x - 80*m_scale.m_x - m_collider->m_extension.m_x;
	}
}

void PlayerObject::Draw(DrawManager* _draw_manager)
{
	_draw_manager->Draw(m_sprite, m_pos.m_x, m_pos.m_y);
}

Vector2 PlayerObject::getPosition(){return m_pos;}
Vector2 PlayerObject::getDimensions(){return m_dimensions;}