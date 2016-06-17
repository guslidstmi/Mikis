#pragma once
#include <SFML\Graphics.hpp>

class Circle
{
public :
	Circle();
	Circle(float x, float y, int colour);
	sf::RectangleShape& m_getRect();

private:
	sf::RectangleShape m_Rect;
};