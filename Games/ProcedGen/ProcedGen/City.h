#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class City : public Tile
{
public :
	City(const float x, const float y, const int id);
	const int m_getCityId();
	sf::RectangleShape& m_getRect();

private :
	sf::RectangleShape m_cityRect;
	const int m_Id;
};