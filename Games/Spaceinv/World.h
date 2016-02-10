#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemies.h"
#include "Interface.h"
#include "Player.h"

class World
{
public:
	World();
	int update(Interface& window);
	void spawnBullet();
	void drawBullets(Interface& window);
	void drawEnemies(Interface& window);
	void drawBombs(Interface& window);
	void deleteBullets();
	void deleteBombs();
	void checkCollision();
	void determineBottom(int id);


private:
	std::vector<Bullet> m_bullets;
	std::vector<Enemy> m_enemies;
	Player m_player;
	Enemies enem;
	bool gameOver;
	int timer = 0;
	int enemytimer = 0;
	int movetimer = 0;
	int bombtimer = 0;
	int bombtimer2 = 0;
	sf::FloatRect paddleBox;
	sf::FloatRect bombBox;
	sf::FloatRect bulletBox;
	sf::FloatRect enemBox;
	sf::Texture m_heart_texture;
	sf::Texture m_enemy_texture;
	sf::Texture m_bomb_texture;
	sf::Texture m_player_texture;
	

	
};

#endif // WORLD_H_
