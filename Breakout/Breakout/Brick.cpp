//Brick.cpp

#include "Brick.h"

#include "DrawManager.h"
#include "Sprite.h"
#include "Collider.h"

Brick::Brick(Sprite* _sprite, Collider* _collider)
	: GameObject(_sprite, _collider)
{
	m_sprite = _sprite;
	m_collider = _collider;
}

Brick::~Brick()
{
	delete m_sprite; m_sprite = nullptr;
	delete m_collider; m_collider = nullptr;
}

void Brick::Update(float _deltatime)
{
	if(m_collider->m_collided)
	{
		Destroy();


	}
}
	
void Brick::Draw(DrawManager* _draw_manager)
{
	_draw_manager->Draw(m_sprite, m_pos.m_x, m_pos.m_y);
}
	
void Brick::setPosition(int _x, int _y)
{
	m_pos = Vector2(_x, _y);
}
	
void Brick::setPosition(Vector2 _pos)
{
	m_pos = _pos;
}

void Brick::setDimension(int _width, int _height)
{
	m_dimensions = Vector2(_width, _height);
}
	
void Brick::setDimension(Vector2 _dimensions)
{
	m_dimensions = _dimensions;
}

void Brick::Destroy()
{
	delete m_sprite; m_sprite = nullptr;
	delete m_collider; m_collider = nullptr;
}

Vector2 Brick::getPosition(){return m_pos;}
Vector2 Brick::getDimensions(){return m_dimensions;}