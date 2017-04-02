#ifndef ENEMYCONTROLLER_H_
#define ENEMYCONTROLLER_H_

#include <vector>
#include "Enemy.h"
#include "Bomb.h"

class EnemyController
{
public:
	EnemyController();
	void dropBomb();
	void determBottom(int id);

	inline int getNumberOfAlive() { return numberOfAlive; }
	inline void decrementNumOfAlive() { --numberOfAlive; }
	inline std::vector<Enemy>& EnemyController::getEnemies() { return m_enemies; }
	inline std::vector<Bomb>& EnemyController::getBombs() { return m_bombs;	}

private:
	std::vector<Enemy> m_enemies;
	std::vector<int> m_bottomEnemies;
	std::vector<Bomb> m_bombs;
	void spawnEnemies();
	int numberOfAlive;
};

#endif
