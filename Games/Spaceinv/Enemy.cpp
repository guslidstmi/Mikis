#include "Enemy.h"

Enemy::Enemy(float x, float y, int id, int row) : 
	m_enemy{}

{
	m_enemy.setSize({60.f, 20.f});
	if (id > 35)
	{
		setBottom();
		m_enemy.setFillColor(sf::Color::Red);
	}
	else
	m_enemy.setFillColor(sf::Color::Blue);
	m_enemy.setPosition(x, y);
	m_enemy.setOrigin(60.f / 2.f, 20.f / 2.f);
	m_id = id;
	m_row = row;
	m_lives = 3;
	m_destroyed = false;
}

bool Enemy::update(int num)
{
	if (isBottom())
	{
		m_enemy.setFillColor(sf::Color::Red);
	}

	if(m_enemy.getPosition().y > 525)
	{
		return true;
	}

	switch (m_row)
	{
	case 0 :
		
		switch (num)
		{
		case 0 :
			velocity.y = +20.f;
			velocity.x = 0;
			m_enemy.move(velocity);
			break;
		case 1 :
			velocity.y = 0;
			velocity.x = +15.f;
			m_enemy.move(velocity);
			break;
		case 2 :
			velocity.y = 0;
			velocity.x = -15.f;
			m_enemy.move(velocity);
			break;
		case 3 :
			velocity.y = 0;
			velocity.x = -15.f;
			m_enemy.move(velocity);
			break;
		case 4 :
			velocity.y = 0;
			velocity.x = +15.f;
			m_enemy.move(velocity);
			break;
		}
		break;
	case 1 :

		switch (num)
		{
		case 0:
			velocity.y = +20.f;
			velocity.x = 0;
			m_enemy.move(velocity);
			break;
		case 1:
			velocity.y = 0;
			velocity.x = -15.f;
			m_enemy.move(velocity);
			break;
		case 2:
			velocity.y = 0;
			velocity.x = +15.f;
			m_enemy.move(velocity);
			break;
		case 3:
			velocity.y = 0;
			velocity.x = +15.f;
			m_enemy.move(velocity);
			break;
		case 4:
			velocity.y = 0;
			velocity.x = -15.f;
			m_enemy.move(velocity);
			break;
		}
		break;
	}
	return false;
}

bool Enemy::isDestroyed() 
{

	return m_destroyed;
}

bool Enemy::isBottom()
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

int Enemy::getId()
{
	return m_id;
}

int Enemy::isDead() 
{
	return m_lives;
}

void Enemy::setLives() 
{
	--m_lives;
}

float Enemy::x()		{ return m_enemy.getPosition().x; }
float Enemy::y()		{ return m_enemy.getPosition().y; }
float Enemy::bottom()	{ return y() + m_enemy.getSize().y / 2.f; }
float Enemy::left()		{ return x() - m_enemy.getSize().x / 2.f; }
float Enemy::right()	{ return x() + m_enemy.getSize().x / 2.f; }