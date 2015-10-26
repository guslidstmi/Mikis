#ifndef PLAYER_H_
#define PLAYER_H_
#pragma once

#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	bool update();
	sf::RectangleShape paddle;
	float y();
	float x();
	float left();
	float right();
	int getLives();
	void reduceLives();

private:
	sf::Vector2f velocity;
	int m_lives;
};

#endif // PLAYER_H_