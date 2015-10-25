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
	float y();
	float x();
	float left();
	float right();

private:
	sf::Vector2f velocity;
	
	
};

#endif // PLAYER_H_