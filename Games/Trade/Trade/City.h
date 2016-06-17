#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class City : public Tile
{
public :
	City(float x, float y, int id);
	int m_getCityId();
	sf::RectangleShape& m_getRect();

private :
	sf::RectangleShape m_cityRect;
	int m_Id;
};