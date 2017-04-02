#include "EnemyController.h"
#include <iostream>
#include <stdlib.h>

namespace {
	constexpr unsigned int x_enemy = 90;
	constexpr unsigned int y_enemy = 40;
};

EnemyController::EnemyController() 
	: m_enemies{}
	, m_bottomEnemies{}
	, m_bombs{}
	, numberOfAlive{0}
{
	spawnEnemies();
}

void EnemyController::spawnEnemies()
{
	float x = 0.0f, y = 0.0f;
	int i, z, id = 1, col = 1;
	for (x = 20.0f, z = 0; z < 9; ++z)
	{
		for (y = 50.0f, i = 1; i < 6; ++i)
		{
			Enemy enemy(x, y, id, i % 2, col);

			if (id % 5 == 0)
			{
				enemy.setBottom();
				m_bottomEnemies.push_back(id);
			}

			m_enemies.push_back(enemy);
			y += y_enemy;

			++id;
		}
		x += x_enemy;
		++col;
	}
	numberOfAlive = m_enemies.size();
}

void EnemyController::determBottom(int id)
{
	while (id % 5 != 0)
	{
		++id;
	}
	// correcting id because id and index does not match.
    for (int i = id - 1; i > id - 6; --i)
	{
        if (!m_enemies[i].isDestroyed())
		{
			m_enemies[i].setBottom();
          	m_bottomEnemies.at(m_enemies[i].getCol() - 1) = m_enemies[i].getId();
           	return;
		}
	}
}

void EnemyController::dropBomb()
{
	srand((uint16_t)time(nullptr));
	int randNum = rand() % 8;

	if (!m_enemies[m_bottomEnemies[randNum] - 1].isDestroyed())
	{
		Bomb bomb(m_enemies[m_bottomEnemies[randNum] - 1].x(), m_enemies[m_bottomEnemies[randNum] - 1].y());

		m_bombs.push_back(bomb);
	}
}