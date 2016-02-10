#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>


class Enemy
{
public:
	sf::Sprite m_enemy;
	Enemy(float x = 0.0, float y = 0.0, int id = 0, int row = 0, int col = 0);
	bool update(int num, sf::Texture& texture);
	bool isDestroyed();
	bool isBottom();
	void setDestroyed();
	void setBottom();
	int getId();
	int isDead();
	void setLives();
	float x();
	float y();

	inline int getCol() const { return m_col; };


private:
	sf::Vector2f velocity;
	int m_lives;
	int m_id;
	int m_row;
	int m_col;
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
