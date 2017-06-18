#include "Shape.h"

Shape::Shape() 
	: m_colour{255, 255, 255}
{}

const void Shape::setColour(int r, int g, int b)
{
	m_colour.R = r;
	m_colour.B = b;
	m_colour.G = g;
}

const Colour& Shape::getColour() const
{
	return m_colour;
}

Shape::~Shape()
{}
