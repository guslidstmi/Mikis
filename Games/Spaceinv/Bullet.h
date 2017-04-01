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
	const bool hasCollided() const;
	void setCollided();
	const float y() const;
	const float x() const;

private:
	sf::Vector2f velocity;
	bool collide;
};

#endif // BULLET_H_
