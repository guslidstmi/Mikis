#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include "Hearts.h"

class Player
{
public:
	Player();
	const bool update(const sf::Texture& texture);
	sf::Sprite paddle;
	const float y();
	const float x();
	const int getLives();
	void reduceLives();
	void popHearts();
	std::vector<Hearts>& getHearts();

private:
	sf::Vector2f velocity;
	int m_lives;
	std::vector<Hearts> m_hearts;
	int m_timer = 0;
};

#endif // PLAYER_H_
