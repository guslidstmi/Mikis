#include "City.h"

City::City(float x, float y, int id) :
	m_Id{ id },
m_cityRect{}
{
	m_cityRect.setSize(sf::Vector2f(40.0, 30.0));
	m_cityRect.setPosition(x, y);
	m_cityRect.setFillColor(sf::Color::Red);
}

int City::m_getCityId()
{
	return m_Id;
}

sf::RectangleShape& City::m_getRect()
{
	return m_cityRect;
}
