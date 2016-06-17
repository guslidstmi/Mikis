#include "Map.h"

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

	int x = 0, y = 0, id = 0;
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
			else if (num > 0.5 && num < 3.0)
			{
				grid[i][j] = 3;
				environment.push_back(Tile(x, y, 3));
			}
			else
			{
				grid[i][j] = 2;
				environment.push_back(Tile(x, y, 2));
			}
			y += 30;
		}
		y = 0;
		x += 40;
	}
}

bool Map::nearbyCity(int i, int j, int grid[20][20])
{
	if (grid[i - 1][j] == 1 || grid[i - 1][j - 1] == 1 || grid[i - 1][j + 1] == 1 ||
		grid[i + 1][j] == 1 || grid[i + 1][j - 1] == 1 || grid[i + 1][j + 1] == 1 ||
		grid[i][j - 1] == 1 || grid[i][j + 1] == 1)
	{
		return true;
	}

	return false;
}
