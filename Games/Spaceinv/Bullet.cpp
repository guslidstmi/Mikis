#include "Bullet.h"

namespace {
	constexpr float OffSet = 10.f;
};

Bullet::Bullet(const float x, const float y) 
	: m_bulletRect{}
{
	m_bulletRect.setRadius(3.f);
	m_bulletRect.setFillColor(sf::Color::Yellow);
	m_bulletRect.setPosition(x, y-5.f);
	m_bulletRect.setOrigin(10.f/2, 20.f/2);
	collide = false;
}

void Bullet::update()
{
	velocity.y -= OffSet;
	m_bulletRect.move(velocity);
	if(m_bulletRect.getPosition().y < 0) 
	{
		collide = true;
	}
}