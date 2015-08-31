#ifndef PLAYER_H_
#define PLAYER_H_
#pragma once

#include <SFML/Graphics.hpp>


class Player
{
public:
	Player();
	void update();
	sf::RectangleShape paddle;

private:
	sf::Vector2f velocity;
	float y();
	float x();
	float left();
	float right();
	
};

#endif // PLAYER_H_