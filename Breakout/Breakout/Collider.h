// Collider.h

#pragma once

#include "Vector2.h"
#include <string>

class Collider {
public:
	Collider();
	Collider(const Vector2 &position, const Vector2 &extension);

	virtual bool Overlap(Collider &other, Vector2 &offset) = 0;

	void setPosition(Vector2 _position);
	Vector2 getPosition();
	Vector2 getExtension();

	Vector2 m_position;
	Vector2 m_extension;

	Vector2 m_prev_position;
	std::string m_direction;

	bool m_collided;
};

class Box : public Collider
{
public:
	Box();
	Box(const Vector2 &_position, const Vector2 &_extension);

	bool Overlap(Collider &other, Vector2 &offset);
};

class Circle : public Collider
{
public: 
	Circle();
	Circle(const Vector2 &_position, const Vector2 &_extension);

	bool Overlap(Collider &other, Vector2 &offset);
};