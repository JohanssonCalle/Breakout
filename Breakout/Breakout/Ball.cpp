//Ball.cpp

#include "Ball.h"
#include "Sprite.h"
#include "Collider.h"
#include "SoundManager.h"
#include "SoundClip.h"
#include "DrawManager.h"

#include "Input.h"

#include <cmath>

float Ball::Random(float min, float max)
{
	return min + (max - min) * ((float)rand() / (float)RAND_MAX);	
}

Ball::Ball(Sprite* _sprite, Collider* _collider)
	: GameObject(_sprite, _collider)
{
	m_soundmanager = new SoundManager();
	m_sound = m_soundmanager->CreateSound("../data/sounds/snd_wall_hit.wav");

	m_sprite = _sprite;
	m_collider = _collider;

	m_radius = _collider->m_extension.m_x/2;

	m_speed = 32.f;
	m_timer = 0.f;
	m_move = false;

	m_dir.m_x = Random(-.7f,.7f);
	m_dir.m_y = Random(0.f, 1.f);
}

Ball::~Ball()
{
	delete m_sprite; m_sprite = nullptr;
	delete m_collider; m_collider = nullptr;
}

void Ball::getKeyboard(Keyboard* _keyboard)
{
	m_keyboard = _keyboard;
}

void Ball::setPosition(int _x, int _y)
{
	m_pos = Vector2(_x, _y);
}

void Ball::setPosition(Vector2 _pos)
{
	m_pos = _pos;
}

void Ball::setDirection(Vector2 _dir)
{
	m_dir = _dir;
}

void Ball::Update(float _deltatime)
{
	if(m_keyboard->IsDownOnce(32))
	{
		m_move = true;
	}

	if(m_move)
	{
		if(m_speed == 0.f)
			m_speed = 32.f;

		if(m_timer >= 15.f)
		{
			m_speed += 0.5f;
			m_timer = 0;
		}

		if(m_pos.m_x > m_window_dimensions.m_x - 80*m_scale.m_x - m_collider->m_extension.m_x)
		{
			m_dir.m_x *= -1;
			m_sound->Play();
		}else if(m_pos.m_x < 80*m_scale.m_x)
		{
			m_dir.m_x *= -1;
			m_sound->Play();
		}else if(m_pos.m_y < 80*m_scale.m_x)
		{
			m_dir.m_y *= -1;
			m_sound->Play();
		}
		if(m_collider->m_collided == true)
		{
			if(m_collider->m_direction == "Left" || m_collider->m_direction == "Right") m_dir.m_x *= -1;
			else if(m_collider->m_direction == "Top" || m_collider->m_direction == "Bottom") m_dir.m_y *= -1;
			m_sound->Play();
		}
		m_timer += _deltatime;
	}else{
		m_speed = 0.f;
	}

	m_pos.m_x = m_dir.m_x*m_speed*_deltatime;
	m_pos.m_y = m_dir.m_y*m_speed*_deltatime;
}

void Ball::Draw(DrawManager* _draw_manager)
{
	_draw_manager->Draw(m_sprite, m_pos.m_x, m_pos.m_y);
}

Sprite* Ball::getSprite(){return m_sprite;}
Collider* Ball::getCollider(){return m_collider;}
float Ball::getRadius(){return m_radius;}
Vector2 Ball::getPosition(){return m_pos;}
Vector2 Ball::getDirection(){return m_dir;}