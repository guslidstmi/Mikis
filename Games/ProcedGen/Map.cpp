#include "Map.h"
#include <iostream>

Map::Map()
{
	generateMap();
}

std::vector<Tile>& Map::getMap()
{
	return environment;
}

std::vector<City>& Map::getCities()
{
	return cities;
}

void Map::generateMap()
{
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::normal_distribution<double> distribution(5.0, 2.0);

	float x = 0, y = 0;
	int id = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			int num = (int)distribution(generator);
			if (num > 0.5 && num < 3.0)
			{
				grid[i][j] = 3;
				environment.push_back(Tile(x, y, 3));
			}
			else
			{
				grid[i][j] = 2;
				environment.push_back(Tile(x, y, 2));
			}
			y += 30.f;
		}
		y = 0.f;
		x += 40.f;
	}
}

bool Map::nearbyCity(int i, int j, int grid[20][20])
{
	if (grid[i - 1][j] == 1 || grid[i - 1][j - 1] == 1 || grid[i - 1][j + 1] == 1 ||
		grid[i + 1][j] == 1 || grid[i + 1][j - 1] == 1 || grid[i + 1][j + 1] == 1 ||
		grid[i][j - 1] == 1 || grid[i][j + 1] == 1 ||
		grid[i - 2][j] == 1 || grid[i - 2][j - 2] == 1 || grid[i - 2][j + 2] == 1 ||
		grid[i + 2][j] == 1 || grid[i + 2][j - 2] == 1 || grid[i + 2][j + 2] == 1 ||
		grid[i][j - 2] == 1 || grid[i][j + 2] == 1)
	{
		return true;
	}

	return false;
}

void Map::generateCities()
{
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::normal_distribution<double> distribution(5.0, 2.0);

	float x = 0.0f, y = 0.0f;
	int id = 1;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			int num = (int)distribution(generator);
			if (num < 0.5 && !nearbyCity(i, j, grid))
			{
				grid[i][j] = 1;
				cities.push_back(City(x, y, id));
				++id;
			}
			y += 30.f;
		}
		y = 0.f;
		x += 40.f;
	}
}

void Map::placeCity(const int x, const int y)
{
	int i = x / 40;
	int j = y / 30;
	grid[i][j] = 1;
	cities.push_back(City((float)(i*40), (float)(j*30), 0));
	generateCities();
}
