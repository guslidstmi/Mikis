#pragma once
#include <SFML\Graphics.hpp>
#include "Circle.h"

class City : public Circle
{
public :
	City(float x, float y);
	int m_getCityId();
	sf::RectangleShape& m_getRect();

private :
	sf::RectangleShape m_cityRect;
};