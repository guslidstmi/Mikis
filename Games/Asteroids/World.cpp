#include "World.h"

World::World()
{}

void World::spawnShot(sf::Vector2f& direction, float& rotation) 
{
	sf::RectangleShape shot{ sf::Vector2f(8, 2) };
	shot.setFillColor(sf::Color::Red);
	shot.setPosition(direction.x + 5.0, direction.y - 15.0);
	shot.setRotation(rotation);

	shots.push_back(shot);

}

void World::spawnAsteroid()
{
	sf::CircleShape asteroid{ 20, 30 };
	asteroid.setFillColor(sf::Color::Yellow);
	int num = rand() % 4;

	if(num == 0)
	{
		asteroid.setPosition(-40.0, static_cast<float>(rand() % 640));
	}
	else if(num == 1)
	{
		asteroid.setPosition(840.0, static_cast<float>(rand() % 640));
	}
	else if(num == 2)
	{
		asteroid.setPosition(static_cast<float>(rand() % 840), -40.0);
	}
	else 
	{
		asteroid.setPosition(static_cast<float>(rand() % 840), 640.0);
	}

	asteroids.push_back(asteroid);
}

void World::update()
{

	for (std::vector<sf::CircleShape>::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		sf::Vector2f pos = it->getPosition();
		if(pos.x < 400 && pos.y < 300)
		{
			it->move(0.1, 0.1);
		}
		else if(pos.x > 400 && pos.y < 300)
		{
			it->move(-0.1, 0.1);
		}
		else if(pos.x < 400 && pos.y > 300)
		{
			it->move(0.1, -0.1);
		}
		else
		{
			it->move(-0.1, -0.1);
		}
	}

	for (std::vector<sf::RectangleShape>::iterator it = shots.begin(); it != shots.end(); ++it)
	{
		if (it->getRotation() > 0.0 && it->getRotation() < 41.0)
		{
			it->move(0.5, 0.5);
		}
		else if (it->getRotation() == 90.0)
		{
			it->move(0.0, 1.0);
		}
		else if (it->getRotation() == 180.0)
		{
			it->move(-1.0, 0.0);
		}
		else if (it->getRotation() == 270.0)
		{
			it->move(0.0, -1.0);
		}
		else if (it->getRotation() == 0.0)
		{
			it->move(1.0, 0.0);
		}
		else if (it->getRotation() > 40.0 && it->getRotation() < 91.0)
		{
			it->move(0.5, 1.0);
		}
		else if (it->getRotation() > 90.0 && it->getRotation() < 141.0)
		{
			it->move(-0.5, 1.0);
		}
		else if (it->getRotation() > 140.0 && it->getRotation() < 181.0)
		{
			it->move(-1.0, 0.5);
		}
		else if (it->getRotation() > 180.0 && it->getRotation() < 221.0)
		{
			it->move(-0.5, -0.5);
		}
		else if (it->getRotation() > 220.0 && it->getRotation() < 271.0)
		{
			it->move(-0.5, -1.0);
		}
		else if (it->getRotation() > 270.0 && it->getRotation() < 321.0)
		{
			it->move(0.5, -1.0);
		}
		else
		{
			it->move(1.0, -1.0);
		}
	}
}
