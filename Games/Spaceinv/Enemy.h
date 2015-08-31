#ifndef ENEMY_H_
#define ENEMY_H_
#pragma once

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	sf::RectangleShape m_enemy;
	Enemy(float x, float y, int id, int row);
	bool update();
	bool isDestroyed();
	bool isBottom();
	void setDestroyed();
	void setBottom();
	int getId();
	int isDead();
	void setLives();
	float left();
	float right();
	float x();
	float y();
	float bottom();


private:
	sf::Vector2f velocity;
	int m_direction;
	int m_lives;
	int m_id;
	int m_row;
	bool m_destroyed;
	bool m_bottom = false;

	
};

#endif // ENEMY_H_