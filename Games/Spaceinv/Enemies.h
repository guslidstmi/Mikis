#ifndef ENEMIES_H_
#define ENEMIES_H_
#pragma once

#include <vector>
#include "Enemy.h"

class Enemies
{
public:
	Enemies();
	std::vector<Enemy>& getEnemies();
	void dropBomb();
	void determBottom();

private:
	std::vector<Enemy> m_enemies;
	void spawnEnemies();

};

#endif