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

	inline const bool Bomb::hasCollided() const { return m_collide; }
	inline void Bomb::setCollided() { m_collide = true; }
	inline const float Bomb::x() const { return m_bomb.getPosition().x; }
	inline const float Bomb::y() const { return m_bomb.getPosition().y; }

private:
	sf::Vector2f velocity;
	bool m_collide;
};

#endif // BOMB_H_
