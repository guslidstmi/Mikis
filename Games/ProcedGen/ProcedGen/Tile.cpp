#include "Tile.h"

Tile::Tile()
{}

Tile::Tile(float x, float y, int colour) :
	m_Rect{}
{
	if (colour == 2)
	{
		m_Rect.setFillColor(sf::Color::Green);
	}
	else
	{
		m_Rect.setFillColor(sf::Color::Blue);
	}

	m_Rect.setSize(sf::Vector2f(4.0,3.0));
	m_Rect.setPosition(x, y);
}

sf::RectangleShape & Tile::m_getRect()
{
	return m_Rect;
}
