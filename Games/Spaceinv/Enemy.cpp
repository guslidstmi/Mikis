#include "Enemy.h"

Enemy::Enemy(float x, float y, int id) : 
	m_enemy{}, 
	left{ 0, 0, 25, 25 }, 
	front{28, 0, 25, 25}, 
	right{52, 0, 25, 25}, 
	explo1{75, 0, 25, 25}, 
	explo2{100, 0, 25, 25}, 
	explo3{125, 0, 25, 25}
{
	m_enemy.setPosition(x, y);
	m_id = id;
	m_lives = 3;
	m_destroyed = false;
}

const bool Enemy::update(const int num, const sf::Texture& texture)
{
	if (m_enemy.getTexture() == nullptr)
	{
		m_enemy.setTexture(texture);
		m_enemy.scale(1.7f, 1.7f);
		m_enemy.setTextureRect(front);
	}
	if (m_enemy.getPosition().y > 525.f && !isDestroyed())
	{
		return true;
	}

	switch (m_row)
	{
	case 0 :
		
		switch (num)
		{
		case 0 :
			velocity.y += 20.f;
			velocity.x = 0;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(front);
			break;
		case 1 :
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(right);
			break;
		case 2 :
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(left);
			break;
		case 3 :
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(left);
			break;
		case 4 :
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(right);
			break;
		}
		break;
	case 1 :

		switch (num)
		{
		case 0:
			velocity.y += 20.f;
			velocity.x = 0;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(front);
			break;
		case 1:
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(left);
			break;
		case 2:
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(right);
			break;
		case 3:
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(right);
			break;
		case 4:
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			m_enemy.setTextureRect(left);
			break;
		}
		break;
	}
	return false;
}

const bool Enemy::isDestroyed() const
{
	return m_destroyed;
}

const bool Enemy::isBottom() const
{
	return m_bottom;
}

void Enemy::setDestroyed() 
{
	m_destroyed = true;
}

void Enemy::setBottom()
{
	m_bottom = true;
}

const int Enemy::getId() const
{
	return m_id;
}

const int Enemy::isDead() const
{
	return m_lives;
}

void Enemy::setLives() 
{
	--m_lives;
}

const float Enemy::x() const	{ return m_enemy.getPosition().x; }
const float Enemy::y() const	{ return m_enemy.getPosition().y; }