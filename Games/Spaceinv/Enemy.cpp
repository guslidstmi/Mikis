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
	if (row == 1)
	{
		m_direction = 1;
	}
	else
	m_direction = 2;
	m_id = id;
	m_row = row;
	m_lives = 3;
	m_destroyed = false;
}

bool Enemy::update() 
{
	if (isBottom())
	{
		m_enemy.setFillColor(sf::Color::Red);
	}

	if(m_enemy.getPosition().y > 525)
	{
		return true;
	}

	if(m_direction == 0)
	{
		velocity.y = +20.f;
		velocity.x = 0;
		m_enemy.move(velocity);
		m_direction = 1;
	}
	else if(m_direction == 1)
	{
		velocity.x = +20.f;
		velocity.y = 0;
		m_enemy.move(velocity);
		m_direction = 2;
	}
	else {
		velocity.x = -20.f;
		velocity.y = 0;
		m_enemy.move(velocity);
		m_direction = 0;
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