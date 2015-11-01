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
	void update(sf::Texture& heart_texture);

private:

	int timer;
	int state;
};


#endif // HEARTS_H_