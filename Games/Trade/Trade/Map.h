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
	void placeCity(int x, int y);

private:
	void generateMap();
	bool nearbyCity(int i, int j, int grid[20][20]);
	void generateCities();

	std::vector<Tile> environment;
	std::vector<City> cities;

	const int gridSize = 20;
	int grid[20][20];
};