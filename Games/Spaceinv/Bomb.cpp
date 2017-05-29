#include "Bomb.h"

namespace {
	constexpr float OffSet = 1.5f;
};

Bomb::Bomb(const float x, const float y) 
	: m_bomb{}
{
	m_bomb.setPosition(x, y + 30.f);
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
	if (m_bomb.getPosition().y > 600.f)
	{
		m_collide = true;
	}
}