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
	if (!m_heart_texture.loadFromFile("Sprites/Heart.png") || !m_enemy_texture.loadFromFile("Sprites/Enemies_full.png") || 
		!m_bomb_texture.loadFromFile("Sprites/bomb.png") || !m_player_texture.loadFromFile("Sprites/Player_canon.png"))
	{
		std::cout << "could not load texture" << std::endl;
	}
}

void World::update(Interface& window)
{
	if(gameOver)
	{
		exit(EXIT_SUCCESS);
	}
	++timer;
	++enemytimer;
	++bombtimer;
	++bombtimer2;
	window.mWindow.draw(m_player.paddle);
	for (auto& heart : m_player.getHearts())
	{
		heart.update(m_heart_texture);
		window.mWindow.draw(heart.m_heart);
	}
	drawEnemies(window);

	gameOver = m_player.update(m_player_texture);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && timer > 15)
	{
		timer = 0;
		spawnBullet();	
	}
	if (bombtimer > 50)
	{
		enem.dropBomb();
		bombtimer = 0;
	}
	checkCollision();
	drawBullets(window);
	drawBombs(window);
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
	if (bombtimer2 > 1)
	{
		for (auto& bomb : enem.getBombs())
		{
			bomb.update(m_bomb_texture);
			window.mWindow.draw(bomb.m_bomb);
		}
		bombtimer2 = 0;
	}

	for (auto& bomb : enem.getBombs())
	{
		window.mWindow.draw(bomb.m_bomb);
	}
}

bool hasCollided(Bullet& b) 
{
	return b.hasCollided();
}

void World::deleteBullets() 
{
	m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), hasCollided), std::end(m_bullets));
}

bool bombHasCollided(Bomb& b)
{
	return b.hasCollided();
}

void World::deleteBombs()
{
	enem.getBombs().erase(std::remove_if(std::begin(enem.getBombs()), std::end(enem.getBombs()), bombHasCollided), std::end(enem.getBombs()));
}

void World::drawEnemies(Interface& window) 
{
	for (auto& x : enem.getEnemies())
	{
		if(enemytimer % 40 == 0)
		{
			gameOver = x.update(movetimer, m_enemy_texture);
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
		bulletBox = bullet.m_bulletRect.getGlobalBounds();
		for (auto& enemy : enem.getEnemies())
		{
			enemBox = enemy.m_enemy.getGlobalBounds();
			if (!enemy.isDestroyed())
			{
				// Check if bullet and enemy has collided, i.e. their x and y position intersect.
				if (bulletBox.intersects(enemBox))
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
				}
			}
		}
	}

	paddleBox = m_player.paddle.getGlobalBounds();

	for (auto& bomb : enem.getBombs())
	{
		bombBox = bomb.m_bomb.getGlobalBounds();
		if (paddleBox.intersects(bombBox))
		{
			bomb.setCollided();
			m_player.reduceLives();
		}
	}
	deleteBombs();
}