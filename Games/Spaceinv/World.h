#ifndef WORLD_H_
#define WORLD_H_
#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "Interface.h"
#include "Player.h"

class World
{
public:
	World();
	void update(Interface& window);
	void spawnBullet();
	void spawnEnemies();
	void drawBullets(Interface& window);
	void drawEnemies(Interface& window);
	void checkCollision();
	void deleteBullets();
	void deleteEnemies();


private:
	std::vector<Bullet> m_bullets;
	std::vector<Enemy> m_enemies;
	Player m_player;
	bool gameOver;
	int timer = 0;
	int enemytimer = 0;

	
};

#endif // WORLD_H_