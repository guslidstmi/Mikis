#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	sf::Sprite m_enemy;
	Enemy(const float x = 0.0, const float y = 0.0, const int id = 0);
	const bool update(const int num, const sf::Texture& texture);
	const bool isDestroyed() const;
	const bool isBottom() const;
	void setDestroyed();
	void setBottom();
	const int getId() const;
	const int isDead() const;
	void setLives();
	const float x() const;
	const float y() const;

private:
	sf::Vector2f velocity;
	int m_lives;
	int m_id;
	bool m_destroyed;
	bool m_bottom = false;
	sf::IntRect left;
	sf::IntRect front;
	sf::IntRect right;
	sf::IntRect explo1;
	sf::IntRect explo2;
	sf::IntRect explo3;



	
};

#endif // ENEMY_H_
