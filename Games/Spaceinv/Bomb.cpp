#include "Bomb.h"

#define OffSet 25.f

Bomb::Bomb(float x, float y) :
m_bombCircle{}
{
	m_bombCircle.setRadius(10.f);
	m_bombCircle.setFillColor(sf::Color::Green);
	m_bombCircle.setPosition(x, y - 5.f);
	m_bombCircle.setOrigin(10.f / 2, 20.f / 2);
	collide = false;
}

void Bomb::update()
{
	velocity.y = +OffSet;
	m_bombCircle.move(velocity);
	if (m_bombCircle.getPosition().y > 525.f)
	{
		collide = true;
	}

}

bool Bomb::hasCollided()
{
	return collide;
}

void Bomb::setCollided()
{
	collide = true;
}

float Bomb::x()		{ return m_bombCircle.getPosition().x; }
float Bomb::y()		{ return m_bombCircle.getPosition().y; }