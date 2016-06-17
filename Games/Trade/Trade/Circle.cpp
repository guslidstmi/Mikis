#include "Circle.h"

Circle::Circle()
{
}

Circle::Circle(float x, float y, int colour) :
	m_Rect{}
{
	if (colour == 2)
	{
		m_Rect.setFillColor(sf::Color::Green);
	}
	else
		m_Rect.setFillColor(sf::Color::Blue);
	m_Rect.setSize(sf::Vector2f(40.0,30.0));
	m_Rect.setPosition(x, y);
}

sf::RectangleShape & Circle::m_getRect()
{
	return m_Rect;
}
