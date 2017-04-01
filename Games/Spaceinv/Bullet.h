#ifndef BULLET_H_
#define BULLET_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Bullet
{
public:
	Bullet(const float x, const float y);
	void update();
	sf::CircleShape m_bulletRect;
	const bool hasCollided();
	void setCollided();
	const float y();
	const float x();

private:
	sf::Vector2f velocity;
	bool collide;
};

#endif // BULLET_H_
