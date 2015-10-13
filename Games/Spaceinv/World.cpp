#include <iostream>
#include <stdlib.h>
#include <vector>
#include "World.h"

class Bullet;
class Player;
class Enemies;

World::World() : m_player{}, m_bullets{}, m_enemies{}
{
	Enemies enem{};
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

void World::deleteBullets() 
{
	m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), hasCollided), std::end(m_bullets));
}

void World::drawEnemies(Interface& window) 
{
	for (auto& x : enem.getEnemies())
	{
		if(enemytimer % 40 == 0)
		{
			gameOver = x.update(movetimer);
		}
		if (!x.isDestroyed())
		window.mWindow.draw(x.m_enemy);
	}
	if (enemytimer % 40 == 0)
	{
		if (movetimer == 4)
			movetimer = 0;
		else ++movetimer;
	}

}

void World::checkCollision() 
{
	for(auto& bullet : m_bullets)
	{
		for (auto& enemy : enem.getEnemies())
		{
			if (!enemy.isDestroyed())
			{
				// Check if bullet and enemy has collided, i.e. their x and y position intersect.
				if (bullet.top() <= enemy.bottom() && bullet.left() <= enemy.right() && bullet.right() >= enemy.left())
				{
					// check if enemy only has one life left, then it's destroyed
 					if (enemy.isDead() == 1)
					{
						enemy.setDestroyed();
 						enem.determBottom(enemy.getId());
						bullet.setCollided();
					}
					// if not destroyed, remove one life.
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
}