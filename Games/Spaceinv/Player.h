#ifndef PLAYER_H_
#define PLAYER_H_
#pragma once

#include <SFML/Graphics.hpp>
#include "Hearts.h"

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
	void popHearts();
	std::vector<Hearts>& getHearts();

private:
	sf::Vector2f velocity;
	int m_lives;
	std::vector<Hearts> m_hearts;
};

#endif // PLAYER_H_