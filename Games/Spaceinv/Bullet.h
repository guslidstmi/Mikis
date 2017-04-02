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

	inline const bool Bullet::hasCollided() const { return collide; }
	inline void Bullet::setCollided() { collide = true; }
	inline const float Bullet::x()	const { return m_bulletRect.getPosition().x; }
	inline const float Bullet::y() const { return m_bulletRect.getPosition().y; }

private:
	sf::Vector2f velocity;
	bool collide;
};

#endif // BULLET_H_
