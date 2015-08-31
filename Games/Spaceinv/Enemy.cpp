#include "Enemy.h"

Enemy::Enemy(float x, float y) : 
	m_enemy{}

{
	m_enemy.setSize({60.f, 20.f});
	m_enemy.setFillColor(sf::Color::Blue);
	m_enemy.setPosition(x, y);
	m_enemy.setOrigin(60.f / 2.f, 20.f / 2.f);
	decision = 0;
	destroyed = false;
	lives = 3;
}

bool Enemy::update() {

	if(m_enemy.getPosition().y > 525)
	{
		return true;
	}

	if(decision == 0)
	{
		velocity.y = +15.f;
		velocity.x = 0;
		m_enemy.move(velocity);
		decision = 1;
	}
	else if(decision == 1)
	{
		velocity.x = +20.f;
		velocity.y = 0;
		m_enemy.move(velocity);
		decision = 2;
	}
	else {
		velocity.x = -20.f;
		velocity.y = 0;
		m_enemy.move(velocity);
		decision = 0;
	}
	return false;
}

bool Enemy::isDestroyed() {

	return destroyed;
}
void Enemy::setDestroyed() {
	destroyed = true;
}

int Enemy::isDead() {
	return lives;
}

void Enemy::setLives() {
	--lives;
}

float Enemy::x()		{ return m_enemy.getPosition().x; }
float Enemy::y()		{ return m_enemy.getPosition().y; }
float Enemy::bottom()	{ return y() + m_enemy.getSize().y / 2.f; }
float Enemy::left()		{ return x() - m_enemy.getSize().x / 2.f; }
float Enemy::right()	{ return x() + m_enemy.getSize().x / 2.f; }