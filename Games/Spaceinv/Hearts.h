#ifndef HEARTS_H_
#define HEARTS_H_

#include "SFML/Graphics.hpp"

class Hearts
{
public:

	Hearts(const float x, const float y);
	sf::Sprite m_heart;
	void update(const sf::Texture& heart_texture);

private:

	int timer;
	int state;
};


#endif // HEARTS_H_
