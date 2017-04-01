#ifndef ENEMYCONTROLLER_H_
#define ENEMYCONTROLLER_H_

#include <vector>
#include "Enemy.h"
#include "Bomb.h"

class EnemyController
{
public:
	EnemyController();
	std::vector<Enemy>& getEnemies();
	std::vector<Bomb>& getBombs();
	void dropBomb();
	void determBottom(int id);
	int numberOfAlive;

private:
	std::vector<Enemy> m_enemies;
	std::vector<int> m_bums;
	std::vector<Bomb> m_bombs;
	void spawnEnemies();

};

#endif
