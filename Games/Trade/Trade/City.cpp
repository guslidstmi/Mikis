#include "City.h"

City::City(float x, float y) : 
m_cityRect{}
{
	m_cityRect.setSize(sf::Vector2f(40.0, 30.0));
	m_cityRect.setPosition(x, y);
	m_cityRect.setFillColor(sf::Color::Red);
}

sf::RectangleShape& City::m_getRect()
{
	return m_cityRect;
}
