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

void World::spawnBullet() {

	Bullet bullet(m_player.paddle.getPosition().x, m_player.paddle.getPosition().y);
	m_bullets.push_back(bullet);

}

void World::drawBullets(Interface& window) {

	for(std::vector<Bullet>::iterator it = m_bullets.begin(); it != m_bullets.end(); ++it)
	{
		it->update();
		window.mWindow.draw(it->m_bulletRect);
	}
	deleteBullets();
}

bool hasCollided(Bullet& b) {
	return b.hasCollided();
}

bool isDestroyed(Enemy& e)
{
	return e.isDestroyed();
}

void World::deleteBullets() {
	m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), hasCollided), std::end(m_bullets));
}

void World::spawnEnemies() {
	int x, y, i, z;
	for(x = 35, y = 20, i = 0; i < 5; ++i)
	{
		for(x = 35, z = 0; z < 9; ++z)
		{
			Enemy enemy(x, y);
			m_enemies.push_back(enemy);
			x += x_enemy;
			
		}
		y += y_enemy;
	}

}

void World::deleteEnemies() {
	m_enemies.erase(std::remove_if(std::begin(m_enemies), std::end(m_enemies), isDestroyed), std::end(m_enemies));
}

void World::drawEnemies(Interface& window) {
	for(std::vector<Enemy>::iterator it = m_enemies.begin(); it != m_enemies.end(); ++it)
	{
		if(enemytimer % 40 == 0)
		{
			gameOver = it->update();
		}
		
		window.mWindow.draw(it->m_enemy);
		deleteEnemies();
	}

}

void World::checkCollision() {

	for(std::vector<Bullet>::iterator b_it = m_bullets.begin(); b_it != m_bullets.end(); ++b_it)
	{
		for(std::vector<Enemy>::iterator e_it = m_enemies.begin(); e_it != m_enemies.end(); ++e_it)
		{
			if(b_it->top() <= e_it->bottom() && b_it->left() <= e_it->right() && b_it->right() >= e_it->left()) {
				if(e_it->isDead() == 1)
				{
					e_it->setDestroyed();
					b_it->setCollided();
				}
				else {
					e_it->setLives();
					b_it->setCollided();
				}
			//	return;
			}
		}
	}

}