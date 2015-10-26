#ifndef HEARTS_H_
#define HEARTS_H_
#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class Hearts
{
public:

	Hearts(int x, int y);
	sf::Sprite m_heart;
	void update();

private:

	sf::Texture heart;
	int timer;
	int state;
	sf::Vector2f scale;
};


#endif // HEARTS_H_