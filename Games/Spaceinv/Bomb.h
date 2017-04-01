#ifndef BOMB_H_
#define BOMB_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bomb
{
public:
	Bomb(const float x, const float y);
	void update(const sf::Texture& texture);
	sf::Sprite m_bomb;
	const bool hasCollided() const;
	void setCollided();
	const float y() const;
	const float x() const;

private:
	sf::Vector2f velocity;
	bool m_collide;


};

#endif // BOMB_H_
