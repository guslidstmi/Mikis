#pragma once
#include <SFML\Graphics.hpp>

class Tile
{
public :
	Tile();
	Tile(float x, float y, int colour);
	sf::RectangleShape& m_getRect();

private:
	sf::RectangleShape m_Rect;
};