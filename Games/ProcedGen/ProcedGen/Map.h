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
	void generateCities(int i, int j);

	std::vector<Tile> m_Environment;
	std::vector<City> m_Cities;

	const int m_GridSize;
	int m_Grid[200][200];
	sf::Texture m_cityTexture;
};