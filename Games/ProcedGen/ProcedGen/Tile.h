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

	Tile(const float x, const float y, Tiletype colour);
	const sf::RectangleShape& getTile()const ;

private:
	sf::RectangleShape m_Rect;
};