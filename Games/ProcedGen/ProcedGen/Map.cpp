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
	Perlin perlin(200, 200);
	perlin.perlin();
	std::cout << perlin.getGridValueByIndex(1,1);
	float x = 0.f, y = 0.f;
	double noiseValue = 0.0;
	int id = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			noiseValue = perlin.getGridValueByIndex(i, j);
			if ( noiseValue < 0.2)
			{
				grid[i][j] = 3;
				environment.push_back(Tile(x, y, 3));
			}
			else
			{
				grid[i][j] = 2;
				environment.push_back(Tile(x, y, 2));
			}
			y += 3.f;
		}
		y = 0.f;
		x += 4.f;
	}
}

bool Map::nearbyCity(int i, int j, int grid[200][200])
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
			int num = distribution(generator);
			if (num < 0.5 && !nearbyCity(i, j, grid))
			{
				grid[i][j] = 1;
				cities.push_back(City(x, y, id));
				++id;
			}
			y += 3.f;
		}
		y = 0.f;
		x += 4.f;
	}
}

void Map::placeCity(const int x, const int y)
{
	int i = x / 4;
	int j = y / 3;
	grid[i][j] = 1;
	cities.push_back(City((float)(i*4), (float)(j*3), 0));
	generateCities();
}

