#include "Bullet.h"

#define OffSet 10.f

Bullet::Bullet(float x, float y) : 
	m_bulletRect{}
{
	m_bulletRect.setRadius(3.f);
	m_bulletRect.setFillColor(sf::Color::Red);
	m_bulletRect.setPosition(x, y-5.f);
	m_bulletRect.setOrigin(10.f/2, 20.f/2);
	collide = false;
}

void Bullet::update()
{
	velocity.y = -OffSet;
	m_bulletRect.move(velocity);
	if(m_bulletRect.getPosition().y < 0) {
		collide = true;
	}

}

bool Bullet::hasCollided() {

	return collide;
}

void Bullet::setCollided() {
	collide = true;
}

float Bullet::x()		{ return m_bulletRect.getPosition().x; }
float Bullet::y()		{ return m_bulletRect.getPosition().y; }
float Bullet::left()	{ return x() - m_bulletRect.getRadius(); }
float Bullet::right()	{ return x() + m_bulletRect.getRadius(); }
float Bullet::top()		{ return y() - m_bulletRect.getRadius(); }