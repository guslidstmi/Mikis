#include <iostream>
#include <stdlib.h>
#include <vector>
#include "World.h"
#include "Interface.h"

World::World()
	: m_bullets{}
	, m_enemies{}
	, m_player{}
	, m_enemyController{}
	, m_gameOver{ false }
	, m_timer{ 0 }
	, m_enemytimer{ 0 }
	, m_movetimer{ 0 }
	, m_bombtimer{ 0 }
	, m_bombtimer2{ 0 }
{
	if (!m_heart_texture.loadFromFile("Sprites/Heart.png") || !m_enemy_texture.loadFromFile("Sprites/Enemies_full.png") || 
		!m_bomb_texture.loadFromFile("Sprites/Bomb.png") || !m_player_texture.loadFromFile("Sprites/Player_canon.png"))
	{
		std::cout << "could not load texture" << std::endl;
	}
}

const int World::update(Interface& window)
{
	if(m_gameOver)
	{
		return 2;
	}
	else if (m_enemyController.numberOfAlive == 0)
	{
		return 3;
	}
	++m_timer;
	++m_enemytimer;
	++m_bombtimer;
	++m_bombtimer2;
	window.mWindow.draw(m_player.paddle);
	for (auto& heart : m_player.getHearts())
	{
		heart.update(m_heart_texture);
		window.mWindow.draw(heart.m_heart);
	}
	drawEnemies(window);

	m_gameOver = m_player.update(m_player_texture);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_timer > 15)
	{
		m_timer = 0;
		spawnBullet();	
	}
	if (m_bombtimer > 50)
	{
		m_enemyController.dropBomb();
		m_bombtimer = 0;
	}
	checkCollision();
	drawBullets(window);
	drawBombs(window);

	return 1;
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

void World::drawBombs(Interface& window)
{
	if (m_bombtimer2 > 1)
	{
		for (auto& bomb : m_enemyController.getBombs())
		{
			bomb.update(m_bomb_texture);
			window.mWindow.draw(bomb.m_bomb);
		}
		m_bombtimer2 = 0;
	}

	for (auto& bomb : m_enemyController.getBombs())
	{
		window.mWindow.draw(bomb.m_bomb);
	}
}

const bool hasCollided(Bullet& b) 
{
	return b.hasCollided();
}

void World::deleteBullets() 
{
	m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), hasCollided), std::end(m_bullets));
}

const bool bombHasCollided(Bomb& b)
{
	return b.hasCollided();
}

void World::deleteBombs()
{
	m_enemyController.getBombs().erase(std::remove_if(std::begin(m_enemyController.getBombs()), std::end(m_enemyController.getBombs()), bombHasCollided), std::end(m_enemyController.getBombs()));
}

void World::drawEnemies(Interface& window) 
{
	for (auto& x : m_enemyController.getEnemies())
	{
		if(m_enemytimer % 40 == 0)
		{
			m_gameOver = x.update(m_movetimer, m_enemy_texture);
		}
		if (!x.isDestroyed())
		window.mWindow.draw(x.m_enemy);
	}
	if (m_enemytimer % 40 == 0)
	{
		if (m_movetimer == 4)
			m_movetimer = 0;
		else ++m_movetimer;
	}

}

void World::checkCollision() 
{
	// TODO: Change so that each bullet does not have to check if they have hit each enemy.
	for(auto& bullet : m_bullets)
	{
		m_bulletBox = bullet.m_bulletRect.getGlobalBounds();
		for (auto& enemy : m_enemyController.getEnemies())
		{
			m_enemyBox = enemy.m_enemy.getGlobalBounds();
			if (!enemy.isDestroyed())
			{
				// Check if bullet and enemy has collided, i.e. their x and y position intersect.
				if (m_bulletBox.intersects(m_enemyBox))
				{
					// check if enemy only has one life left, then it's destroyed
 					if (enemy.isDead() == 1)
					{
						--m_enemyController.numberOfAlive;
						enemy.setDestroyed();
 						m_enemyController.determBottom(enemy.getId());
						bullet.setCollided();
					}
					// if not destroyed, remove one life.
					else
					{
						enemy.setLives();
						bullet.setCollided();
					}
				}
			}
		}
	}

	m_paddleBox = m_player.paddle.getGlobalBounds();

	for (auto& bomb : m_enemyController.getBombs())
	{
		m_bombBox = bomb.m_bomb.getGlobalBounds();
		if (m_paddleBox.intersects(m_bombBox))
		{
			bomb.setCollided();
			m_player.reduceLives();
		}
	}
	deleteBombs();
}