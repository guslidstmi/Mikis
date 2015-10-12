#ifndef ENEMY_H_
#define ENEMY_H_
#pragma once

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	sf::RectangleShape m_enemy;
	Enemy(float x, float y, int id, int row, int col);
	bool update(int num);
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
	void setNext(Enemy* enemy);
	void setPrev(Enemy* enemy);
	Enemy* getNext();
	Enemy* getPrev();


private:
	sf::Vector2f velocity;
	int m_lives;
	int m_id;
	int m_row;
	int m_col;
	bool m_destroyed;
	bool m_bottom = false;
	Enemy* m_previous;
	Enemy* m_next;

	
};

#endif // ENEMY_H_