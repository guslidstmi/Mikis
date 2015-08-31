#include <iostream>
#include <stdlib.h>
#include <vector>
#include "World.h"

#define x_enemy 90
#define y_enemy 40

class Bullet;
class Player;
class Enemy;

World::World() : m_player{}, m_bullets{}, m_enemies{}
{
	spawnEnemies();
	gameOver = false;
}

void World::update(Interface& window)
{
	if(gameOver)
	{
		exit(EXIT_SUCCESS);
	}
	++timer;
	++enemytimer;
	window.mWindow.draw(m_player.paddle);
	drawEnemies(window);

	m_player.update();
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && timer > 15)
	{
		timer = 0;
		spawnBullet();	
	}
	checkCollision();
	drawBullets(window);
	
}

void World::spawnBullet() 
{

	Bullet bullet(m_player.paddle.getPosition().x, m_player.paddle.getPosition().y);
	m_bullets.push_back(bullet);

}

void World::drawBullets(Interface& window) 
{

	for (auto& x : m_bullets)
	{
		x.update();
		window.mWindow.draw(x.m_bulletRect);
	}
	deleteBullets();
}

bool hasCollided(Bullet& b) 
{
	return b.hasCollided();
}

bool isDestroyed(Enemy& e)
{
	return e.isDestroyed();
}

void World::deleteBullets() 
{
	m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), hasCollided), std::end(m_bullets));
}

void World::spawnEnemies() 
{
	int x, y, i, z, id = 0;
	for(x = 35, y = 20, i = 0; i < 5; ++i)
	{
		for(x = 35, z = 0; z < 9; ++z)
		{		
			Enemy enemy(x, y, id, i % 2);
			m_enemies.push_back(enemy);
			x += x_enemy;
			++id;
		}
		y += y_enemy;
	}
}

void World::deleteEnemies() 
{
	m_enemies.erase(std::remove_if(std::begin(m_enemies), std::end(m_enemies), isDestroyed), std::end(m_enemies));
}

void World::drawEnemies(Interface& window) 
{
	for(auto& x : m_enemies)
	{
		if(enemytimer % 40 == 0)
		{
			gameOver = x.update(movetimer);
		}
		window.mWindow.draw(x.m_enemy);
	}
	if (enemytimer % 40 == 0)
	{
		if (movetimer == 4)
			movetimer = 0;
		else ++movetimer;
	}
	
	deleteEnemies();
}

void World::checkCollision() 
{
	for(auto& bullet : m_bullets)
	{
		for(auto& enemy : m_enemies)
		{
			if(bullet.top() <= enemy.bottom() && bullet.left() <= enemy.right() && bullet.right() >= enemy.left()) 
			{
				if(enemy.isDead() == 1)
				{
					enemy.setDestroyed();
					if (enemy.getId() > 8)
					m_enemies[enemy.getId() - 9].setBottom();
					bullet.setCollided();
				}
				else 
				{
					enemy.setLives();
					bullet.setCollided();
				}
			//	return;
			}
		}
	}
}