#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "City.h"
#include "Circle.h"
#include <random>

bool nearbyCity(int i, int j, int grid[20][20]);


int main()
{
	sf::RenderWindow mWindow(sf::VideoMode(800, 600), "Trade Game");
	mWindow.setFramerateLimit(60);
	const int gridSize = 20;
	sf::Event event;
	std::vector<City> cities;
	std::vector<Circle> environment;
	int grid[gridSize][gridSize];

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::normal_distribution<double> distribution(5.0, 2.0);

	int x = 0, y = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			int num = distribution(generator);
			if (num < 0.5 && !nearbyCity(i, j, grid))
			{
				grid[i][j] = 1;
				cities.push_back(City(x, y));
			}
			else if (num > 0.5 && num < 3.0)
			{
				grid[i][j] = 3;
				environment.push_back(Circle(x, y, 3));
			}
			else
			{
				grid[i][j] = 2;
				environment.push_back(Circle(x, y, 2));
			}
			y += 30;
		}
		y = 0;
		x += 40;
	}

	while (mWindow.isOpen())
	{
		mWindow.pollEvent(event);

		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
		for (int i = 0; i < environment.size(); ++i)
		{
			mWindow.draw(environment[i].m_getRect());
		}
		for (int i = 0; i < cities.size(); ++i)
		{
			mWindow.draw(cities[i].m_getRect());
		}
		mWindow.display();
	}
}

bool nearbyCity(int i, int j, int grid[20][20])
{
	if (grid[i - 1][j] == 1 || grid[i-1][j-1] == 1 || grid[i + 1][j - 1] == 1 || 
		grid[i + 1][j] == 1 || grid[i + 1][j - 1] == 1 || grid[i + 1][j + 1] == 1 ||
		grid[i][j - 1] == 1 || grid[i][j + 1] == 1)
	{
		return true;
	}

	return false;
}
