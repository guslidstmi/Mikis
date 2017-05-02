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
	Perlin perlin(gridSize, gridSize);

	float x = 0.f, y = 0.f;
	double noiseValue = 0.0;
	int id = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			noiseValue = perlin.generatePerlin(i, j, 0.8, 12, 0.5);
			if ( noiseValue < 0.39)
			{
				grid[i][j] = 1;
				environment.push_back(Tile(x, y, Tile::Tiletype::WATER));
			}
			else if (noiseValue < 0.44)
			{
				grid[i][j] = 2;
				environment.push_back(Tile(x, y, Tile::Tiletype::SHALLOWWATER));
			}
			else if (noiseValue < 0.45)
			{
				grid[i][j] = 3;
				environment.push_back(Tile(x, y, Tile::Tiletype::BEACH));
			}
			else if(noiseValue < 0.59)
			{
				grid[i][j] = 4;
				environment.push_back(Tile(x, y, Tile::Tiletype::LAND));
			}
			else if (noiseValue < 0.65)
			{
				grid[i][j] = 5;
				environment.push_back(Tile(x, y, Tile::Tiletype::FORREST));
			}
			else if (noiseValue > 0.65)
			{
				grid[i][j] = 6;
				environment.push_back(Tile(x, y, Tile::Tiletype::MOUNTAIN));
			}
			
			y += 3.f;
		}
		y = 0.f;
		x += 4.f;
	}
}

bool Map::nearbyCity(int i, int j, int grid[200][200])
{
	if (grid[i - 1][j] == 0 || grid[i - 1][j - 1] == 0 || grid[i - 1][j + 1] == 0 ||
		grid[i + 1][j] == 0 || grid[i + 1][j - 1] == 0 || grid[i + 1][j + 1] == 0 ||
		grid[i][j - 1] == 0 || grid[i][j + 1] == 0 ||
		grid[i - 2][j] == 0 || grid[i - 2][j - 2] == 0 || grid[i - 2][j + 2] == 0 ||
		grid[i + 2][j] == 0 || grid[i + 2][j - 2] == 0 || grid[i + 2][j + 2] == 0 ||
		grid[i][j - 2] == 0 || grid[i][j + 2] == 0)
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
			double num = distribution(generator);
			if (num < 0.1 && !nearbyCity(i, j, grid) && grid[i][j] == 4)
			{

				grid[i][j] = 5;
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
	grid[i][j] = 0;
	cities.push_back(City((float)(i*4), (float)(j*3), 0));
	generateCities();
}

