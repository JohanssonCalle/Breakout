// Collider.cpp

#include <cstdio>
#include <cmath>
#include "Collider.h"

Collider::Collider() 
: m_position(0.0f, 0.0f)
, m_extension(0.0f, 0.0f)
{
};

Collider::Collider(const Vector2 &position, const Vector2 &extension)
: m_position(position)
, m_extension(extension)
{
};

//bool Collider::Overlap(Collider &other, Vector2 &offset) {
//	float A = m_extension.m_x * 0.5f;
//	float B = other.m_extension.m_x * 0.5f;
//	float C = (m_position.m_x + A) - (other.m_position.m_x + B);
//	if(fabs(C) <= A + B) {
//		float Q = m_extension.m_y * 0.5f;
//		float P = other.m_extension.m_y * 0.5f;
//		float Z = (m_position.m_y + Q) - (other.m_position.m_y + P);
//		if(fabs(Z) <= Q + P) {
//			float dx = ceilf(fabs(C) - (A + B));
//			float dy = ceilf(fabs(Z) - (Q + P));
//			if(dx >= dy) {
//				if(m_position.m_x < other.m_position.m_x) {
//					dx = -dx;
//				};
//				offset.m_x = dx;
//				other.m_position.m_x += dx;
//			}
//			else {
//				if(m_position.m_y < other.m_position.m_y) {
//					dy = -dy;
//				};
//				offset.m_y = dy;
//				other.m_position.m_y += dy;
//			};
//			return true;
//		};
//	};
//	return false;
//};

Box::Box()
	: Collider()
{
	m_position = Vector2(0.0f,0.0f);
	m_extension = Vector2(0.0f,0.0f);

	m_prev_position = m_position;
	m_direction = "";
}

Box::Box(const Vector2 &_position, const Vector2 &_extension)
	: Collider(_position, _extension)
{
	m_position = _position;
	m_extension = _extension;

	m_prev_position = m_position;
	m_direction = "";
}

bool Box::Overlap(Collider &other, Vector2 &offset)
{
	float A = m_extension.m_x * 0.5f;
	float B = other.m_extension.m_x * 0.5f;
	float C = (m_position.m_x + A) - (other.m_position.m_x + B);
	if(fabs(C) <= A + B) {
		float Q = m_extension.m_y * 0.5f;
		float P = other.m_extension.m_y * 0.5f;
		float Z = (m_position.m_y + Q) - (other.m_position.m_y + P);
		if(fabs(Z) <= Q + P) {
			float dx = ceilf(fabs(C) - (A + B));
			float dy = ceilf(fabs(Z) - (Q + P));
			if(dx >= dy) {
				if(m_position.m_x < other.m_position.m_x) {
					dx = -dx;
				};
				offset.m_x = dx;
				other.m_position.m_x += dx;
			}
			else {
				if(m_position.m_y < other.m_position.m_y) {
					dy = -dy;
				};
				offset.m_y = dy;
				other.m_position.m_y += dy;
			};
			return true;
		};
	};
	return false;
}

Circle::Circle()
	: Collider()
{
	m_position = Vector2(0.0f,0.0f);
	m_extension = Vector2(0.0f,0.0f);

	m_prev_position = m_position;
	m_direction = "";
}

Circle::Circle(const Vector2 &_position, const Vector2 &_extension)
	: Collider(_position, _extension)
{
	m_position = _position;
	m_extension = _extension;

	m_prev_position = m_position;
	m_direction = "";
}

bool Circle::Overlap(Collider &other, Vector2 &offset)
{
	float radius = m_extension.m_x/2;
	Vector2 center = Vector2(m_position.m_x + radius, m_position.m_y + radius);
	

	if(	center.m_x + radius > other.m_position.m_x && center.m_x - radius < other.m_position.m_x + other.m_extension.m_x &&
		center.m_y + radius > other.m_position.m_y && center.m_y - radius < other.m_position.m_y + other.m_extension.m_y)
	{
		if(m_position.m_x <= other.m_position.m_x && m_position.m_y > other.m_position.m_y && m_position.m_y < other.m_position.m_y + other.m_extension.m_y)
		{
			m_direction = "Left";
		}
		else if(m_position.m_y <= other.m_position.m_y && m_position.m_x > other.m_position.m_x && m_position.m_x < other.m_position.m_x + other.m_extension.m_x)
		{
			m_direction = "Top";
		}
		else if(m_position.m_y > other.m_position.m_y && m_position.m_y < other.m_position.m_y + other.m_extension.m_y && m_position.m_x >= other.m_position.m_x + other.m_extension.m_x)
		{
			m_direction = "Right";
		}
		else if(m_position.m_x > other.m_position.m_x && m_position.m_y >= other.m_position.m_y + other.m_extension.m_y && m_position.m_x < other.m_position.m_x + other.m_extension.m_x)
		{
			m_direction = "Bottom";
		}

		m_prev_position = m_position;
		return true;
	}

	m_prev_position = m_position;
	return false;
}