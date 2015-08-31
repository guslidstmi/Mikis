#ifndef ENEMY_H_
#define ENEMY_H_
#pragma once

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	sf::RectangleShape m_enemy;
	Enemy(float x, float y);
	bool update();
	bool isDestroyed();
	void setDestroyed();
	int isDead();
	void setLives();
	float left();
	float right();
	float x();
	float y();
	float bottom();


private:
	sf::Vector2f velocity;
	int decision;
	int lives;
	bool destroyed;

	
};

#endif // ENEMY_H_