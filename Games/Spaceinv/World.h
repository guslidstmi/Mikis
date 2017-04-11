#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "EnemyController.h"
#include "Player.h"

class Interface;

class World
{
public:
	World();
	enum class State { starting, play, endLose, endWin };
	World::State update(Interface& window);
	void spawnBullet();
	void drawBullets(Interface& window);
	void drawEnemies(Interface& window);
	void drawBombs(Interface& window);
	void deleteBullets();
	void deleteBombs();
	void checkCollision();
	State state;


private:
	std::vector<Bullet> m_bullets;
	std::vector<Enemy> m_enemies;
	Player m_player;
	EnemyController m_enemyController;
	bool m_gameOver;
	int m_timer;
	int m_enemytimer;
	int m_movetimer;
	int m_bombtimer;
	int m_bombtimer2;
	sf::FloatRect m_paddleBox;
	sf::FloatRect m_bombBox;
	sf::FloatRect m_bulletBox;
	sf::FloatRect m_enemyBox;
	sf::Texture m_heart_texture;
	sf::Texture m_enemy_texture;
	sf::Texture m_bomb_texture;
	sf::Texture m_player_texture;
	sf::SoundBuffer buffer;
	sf::Sound bulletSound;
};

#endif // WORLD_H_
