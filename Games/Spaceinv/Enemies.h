#ifndef ENEMIES_H_
#define ENEMIES_H_
#pragma once

#include <vector>
#include "Enemy.h"
#include "Bomb.h"

class Enemies
{
public:
	Enemies();
	std::vector<Enemy>& getEnemies();
	std::vector<Bomb>& getBombs();
	void dropBomb();
	void determBottom(int id);

private:
	std::vector<Enemy> m_enemies;
	std::vector<int> m_bums;
	std::vector<Bomb> m_bombs;
	void spawnEnemies();

};

#endif