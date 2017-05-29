#include "Tile.h"


Tile::Tile(const float x, const float y, Tiletype colour) :
	m_Rect{}
{
	switch (colour)
	{
	case Tiletype::LAND: m_Rect.setFillColor(sf::Color(0, 153, 76)); break;
	case Tiletype::FORREST: m_Rect.setFillColor(sf::Color(0, 102, 51)); break;
	case Tiletype::BEACH: m_Rect.setFillColor(sf::Color(255, 248, 220)); break;
	case Tiletype::SHALLOWWATER: m_Rect.setFillColor(sf::Color(102, 178, 255)); break;
	case Tiletype::WATER: m_Rect.setFillColor(sf::Color(51,51,255)); break;
	case Tiletype::MOUNTAIN: m_Rect.setFillColor(sf::Color(224, 224, 224)); break;
	}

	m_Rect.setSize(sf::Vector2f(4.0,3.0));
	m_Rect.setPosition(x, y);
}

const sf::RectangleShape & Tile::getTile() const 
{
	return m_Rect;
}
