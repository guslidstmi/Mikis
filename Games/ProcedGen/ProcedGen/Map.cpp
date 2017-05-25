#include "Map.h"
#include <iostream>

Map::Map() :
	m_GridSize{200}
{
	generateMap();

	if (!m_cityTexture.loadFromFile("Sprites/Houses.png"))
	{
		std::cout << "could not load texture";
	}
}

std::vector<Tile>& Map::getMap()
{
	return m_Environment;
}

std::vector<City>& Map::getCities()
{
	return m_Cities;
}

void Map::generateMap()
{
	Perlin perlin(m_GridSize, m_GridSize);
	Perlin perlin2(m_GridSize, m_GridSize);

	float x = 0.f, y = 0.f;
	double noiseValue = 0.0;
	for (int i = 0; i < m_GridSize; ++i)
	{
		for (int j = 0; j < m_GridSize; ++j)
		{
			noiseValue = perlin.generatePerlin(i, j, 0.8, 12, 0.5);
			if ( noiseValue < 0.39)
			{
				m_Grid[i][j] = 1;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::WATER));
			}
			else if (noiseValue < 0.44)
			{
				m_Grid[i][j] = 2;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::SHALLOWWATER));
			}
			else if (noiseValue < 0.45)
			{
				m_Grid[i][j] = 3;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::BEACH));
			}
			else if(noiseValue < 0.62)
			{
				m_Grid[i][j] = 4;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::LAND));
			}
			else if (noiseValue > 0.62)
			{
				m_Grid[i][j] = 6;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::MOUNTAIN));
			}
			
			y += 3.f;
		}
		y = 0.f;
		x += 4.f;
	}

	x = 0.f, y = 0.f;
	noiseValue = 0.0;
	for (int i = 0; i < m_GridSize; ++i)
	{
		for (int j = 0; j < m_GridSize; ++j)
		{
			if (m_Grid[i][j] == 4)
			{
				noiseValue = perlin2.generatePerlin(i, j, 0.8, 12, 0.5);
				if (noiseValue < 0.42 || noiseValue > 0.58)
				{
				m_Grid[i][j] = 5;
				m_Environment.push_back(Tile(x, y, Tile::Tiletype::FORREST));
				}
			}

			y += 3.f;
		}
		y = 0.f;
		x += 4.f;
	}
}

void Map::generateCities(int playerCityX, int playerCityY)
{
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);

	float x = 0.0f, y = 0.0f;
	int id = 1;
	for (int i = 0; i < m_GridSize; i+=5)
	{
		for (int j = 0; j < m_GridSize; j+=5)
		{
			if ((i < playerCityX - 20 || i > playerCityX + 20) && (j < playerCityX - 20 || j > playerCityY + 20))
			{
				double num = distribution(generator);
				if (num < 0.008 && m_Grid[i][j] == 4)
				{

					m_Grid[i][j] = 5;
					m_Cities.push_back(City(x, y, id, m_cityTexture));
					++id;
				}
			}
			y += (3.f*5);
		}
		y = 0.f;
		x += (4.f*5);
	}
}

void Map::placeCity(const int x, const int y)
{
	int cityXPos = x / 4;
	int cityYPos = y / 3;
	m_Grid[cityXPos][cityYPos] = 0;
	m_Cities.push_back(City((float)(cityXPos *4), (float)(cityYPos *3), 0, m_cityTexture));
	generateCities(cityXPos, cityYPos);
}

