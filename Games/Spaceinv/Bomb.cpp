#include "Bomb.h"

namespace {
	constexpr float OffSet = 25.f;
};

Bomb::Bomb(const float x, const float y) :
m_bomb{}
{
	m_bomb.setPosition(x, y - 5.f);
	m_bomb.setOrigin(10.f / 2, 20.f / 2);
	m_collide = false;
}

void Bomb::update(const sf::Texture& texture)
{
	if (m_bomb.getTexture() == nullptr)
	{
		m_bomb.setTexture(texture);
	}
	velocity.y += OffSet;
	m_bomb.move(velocity);
	if (m_bomb.getPosition().y > 525.f)
	{
		m_collide = true;
	}
}

const bool Bomb::hasCollided() const
{
	return m_collide;
}

void Bomb::setCollided()
{
	m_collide = true;
}

const float Bomb::x() const		{ return m_bomb.getPosition().x; }
const float Bomb::y() const		{ return m_bomb.getPosition().y; }