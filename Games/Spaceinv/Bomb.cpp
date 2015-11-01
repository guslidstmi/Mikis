#include "Bomb.h"

#define OffSet 25.f

Bomb::Bomb(float x, float y) :
m_bomb{}
{
	m_bomb.setPosition(x, y - 5.f);
	m_bomb.setOrigin(10.f / 2, 20.f / 2);
	collide = false;
}

void Bomb::update(sf::Texture& texture)
{
	if (m_bomb.getTexture() == NULL)
	{
		m_bomb.setTexture(texture);
	}
	velocity.y = +OffSet;
	m_bomb.move(velocity);
	if (m_bomb.getPosition().y > 525.f)
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

float Bomb::x()		{ return m_bomb.getPosition().x; }
float Bomb::y()		{ return m_bomb.getPosition().y; }