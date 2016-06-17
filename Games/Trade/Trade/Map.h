#pragma once
#include "Tile.h"
#include "City.h"
#include <random>

class Map
{
public:
	Map();
	std::vector<Tile>& getMap();
	std::vector<City>& getCities();

private:
	void generateMap();
	bool nearbyCity(int i, int j, int grid[20][20]);

	std::vector<Tile> environment;
	std::vector<City> cities;

	const int gridSize = 20;
	int grid[20][20];
};