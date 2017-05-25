#pragma once
#include <SFML\Graphics.hpp>

class Tile
{
public:
	enum class Tiletype {
		LAND,
		FORREST,
		BEACH,
		SHALLOWWATER,
		WATER,
		MOUNTAIN
	};

	Tile(float x, float y, Tiletype colour);
	sf::RectangleShape& m_getCity();

private:
	sf::RectangleShape m_Rect;
};