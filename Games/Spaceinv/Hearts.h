#ifndef HEARTS_H_
#define HEARTS_H_

#include "SFML/Graphics.hpp"

class Hearts
{
public:
	Hearts(const float x, const float y);
	void update(const sf::Texture& heart_texture);
	sf::Sprite m_heart;

private:
	int timer;
	int state;
};
#endif // HEARTS_H_
