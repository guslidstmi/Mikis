#include "Enemies.h"
#include <iostream>

#define x_enemy 90
#define y_enemy 40

Enemies::Enemies() : 
	m_enemies{}
{
	spawnEnemies();
}

void Enemies::spawnEnemies()
{
	Enemy* head = nullptr;
	Enemy* next = nullptr;
	Enemy* prev = nullptr;

	int x, y, i, z, id = 1;
	for (x = 35, y = 20, z = 0; z < 9; ++z)
	{
		for (y = 20, i = 1; i < 6; ++i)
		{
			Enemy enemy(x, y, id, i % 2, i % 9);
			next = &enemy;
			if (i == 1)
			{
				head = &enemy;
				head->setPrev(nullptr);
				prev = &enemy;
			}
			else if (i == 5)
			{

			}
			else
			{
				next->setPrev(*prev);
				prev->setNext(enemy);
				prev = &enemy;
			}
			if (i % 5 == 0)
			{
				enemy.setBottom();
			}
			m_enemies.push_back(enemy);
			y += y_enemy;
			++id;
		}
		for (i = 0; i < 5; ++i)
		{
			std::cout << head->getId() << " enemyId" << std::endl;
			head = head->getNext();
		}
		x += x_enemy;
	}
}

std::vector<Enemy>& Enemies::getEnemies()
{
	return m_enemies;
}

void Enemies::determBottom()
{

}