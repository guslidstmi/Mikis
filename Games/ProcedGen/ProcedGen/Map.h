#pragma once
#include "Tile.h"
#include "City.h"
#include "Perlin.h"
#include <random>

class Map
{
public:
	Map();
	std::vector<Tile>& getMap();
	std::vector<City>& getCities();
	void placeCity(const int x, const int y);

private:
	void generateMap();
	bool nearbyCity(int i, int j, int grid[200][200]);
	void generateCities();

	std::vector<Tile> environment;
	std::vector<City> cities;

	const int gridSize = 200;
	int grid[200][200];
};