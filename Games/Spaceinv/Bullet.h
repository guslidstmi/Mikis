#ifndef BULLET_H_
#define BULLET_H_
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{
public:
	Bullet(float x, float y);
	void update();
	sf::CircleShape m_bulletRect;
	bool hasCollided();
	void setCollided();
	float y();
	float x();
	float left();
	float right();
	float top();
	float bottom();

private:
	sf::Vector2f velocity;
	bool collide;

	
};

#endif // BULLET_H_
