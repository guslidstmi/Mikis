#include "Cuboid.h"

Cuboid::Cuboid(double length, double height, double depth) 
	: m_dimensions{length, height, depth, 0}
	, m_type{"Cuboid"}
{}

double Cuboid::getVolume() const
{
	return m_dimensions.length * m_dimensions.height * m_dimensions.depth;
}

double Cuboid::getSurface() const
{
	double areaFront = m_dimensions.length * m_dimensions.height;
	double areaTop = m_dimensions.length * m_dimensions.depth;
	double areaSide = m_dimensions.depth * m_dimensions.height;
	return areaFront + areaTop + areaSide;
}

const std::string& Cuboid::getTypeName() const
{
	return m_type;
}

void Cuboid::setDimensions(double length, double height, double depth)
{
	m_dimensions.length = length;
	m_dimensions.height = height;
	m_dimensions.depth = depth;
}

const Dimensions& Cuboid::getDimensions() const
{
	return m_dimensions;
}

Cuboid::~Cuboid()
{}

