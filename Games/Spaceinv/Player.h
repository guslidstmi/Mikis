#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include "Hearts.h"

class Player
{
public:
	Player();
	const bool update(const sf::Texture& texture);
	void reduceLives();
	void popHearts();
	sf::Sprite paddle;

	inline std::vector<Hearts>& Player::getHearts()	{ return m_hearts; }
	inline const int Player::getLives() const { return m_lives; }
	inline const float Player::x() const { return paddle.getPosition().x; }
	inline const float Player::y() const { return paddle.getPosition().y; }

private:
	sf::Vector2f velocity;
	std::vector<Hearts> m_hearts;
	int m_lives;
	int m_timer;
};
#endif // PLAYER_H_
