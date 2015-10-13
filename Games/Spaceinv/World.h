#ifndef WORLD_H_
#define WORLD_H_
#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemies.h"
#include "Interface.h"
#include "Player.h"

class World
{
public:
	World();
	void update(Interface& window);
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

	
};

#endif // WORLD_H_