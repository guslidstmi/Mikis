#include "City.h"

City::City(const float x, const float y, const int id) :
	m_Id{ id },
m_cityRect{}
{
	m_cityRect.setSize(sf::Vector2f(2.0, 3.0));
	m_cityRect.setPosition(x, y);
	if (id > 0)
	{
	m_cityRect.setFillColor(sf::Color::Red);
	}
	else
	{
		m_cityRect.setFillColor(sf::Color::Magenta);
	}
}

const int City::m_getCityId()
{
	return m_Id;
}

sf::RectangleShape& City::m_getRect()
{
	return m_cityRect;
}
