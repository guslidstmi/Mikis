#ifndef BOMB_H_
#define BOMB_H_
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bomb
{
public:
	Bomb(float x, float y);
	void update();
	sf::CircleShape m_bombCircle;
	bool hasCollided();
	void setCollided();
	float y();
	float x();

private:
	sf::Vector2f velocity;
	bool collide;


};

#endif // BOMB_H_
