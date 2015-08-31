#ifndef WORLD_H_
#define WORLD_H_
#pragma once

#include <SFML/Graphics.hpp>

class World
{

public:
	World();
	void spawnShot(sf::Vector2f& direction, float& rotation);
	void spawnAsteroid();
	void update();

	std::vector<sf::RectangleShape> shots;
	std::vector<sf::CircleShape> asteroids;

private:
	bool testCollision();
};


#endif // WORLD_H_