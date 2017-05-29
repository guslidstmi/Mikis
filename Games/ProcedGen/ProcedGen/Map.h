#pragma once
#include "Tile.h"
#include "City.h"
#include "Perlin.h"
#include <random>

class Map
{
public:
	Map();
	const std::vector<Tile>& getMap() const;
	const std::vector<City>& getCities() const;
	void placeCity(const int x, const int y);

private:
	void generateMap();
	void generateCities(const int i, const int j);

	std::vector<Tile> m_Environment;
	std::vector<City> m_Cities;

	const int m_GridSize;
	int m_Grid[200][200];
	sf::Texture m_cityTexture;
};