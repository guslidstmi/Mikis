#include "Enemies.h"
#include <iostream>
#include <stdlib.h>

#define x_enemy 90
#define y_enemy 40

Enemies::Enemies() : 
	m_enemies{}, m_bums{}, m_bombs{}
{
	spawnEnemies();
}

void Enemies::spawnEnemies()
{
	float x = 0.0f, y = 0.0f;
	int i, z, id = 1, col = 1;
	for (x = 35.0f, z = 0; z < 9; ++z)
	{
		for (y = 50.0f, i = 1; i < 6; ++i)
		{
			Enemy enemy(x, y, id, i % 2, col);

			if (id % 5 == 0)
			{
				enemy.setBottom();
				m_bums.push_back(id);
			}

			m_enemies.push_back(enemy);
			y += y_enemy;

			++id;
		}
		x += x_enemy;
		++col;
	}
}

std::vector<Enemy>& Enemies::getEnemies()
{
	return m_enemies;
}

std::vector<Bomb>& Enemies::getBombs()
{
	return m_bombs;
}

void Enemies::determBottom(int id)
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
          	m_bums.at(m_enemies[i].getCol() - 1) = m_enemies[i].getId();
           	return;
		}
	}
}

void Enemies::dropBomb()
{
	srand(time(NULL));
	int randNum = rand() % 8;

	if (!m_enemies[m_bums[randNum] - 1].isDestroyed())
	{
		Bomb bomb(m_enemies[m_bums[randNum] - 1].x(), m_enemies[m_bums[randNum] - 1].y());

		m_bombs.push_back(bomb);
	}


}