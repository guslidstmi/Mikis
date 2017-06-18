#include "Cone.h"
#include <cmath>
#include <iostream>

Cone::Cone(double height, double radius) 
	: m_dimensions{ 0, height, 0, radius }
	, m_type{"Cone"}
{}

double Cone::getVolume() const
{
	double area = PI * pow(m_dimensions.radius, 2);
	double volume = (1.0/3.0) * (area * m_dimensions.height);
	return volume;
}

double Cone::getSurface() const
{
	double slantHeight = sqrt(pow(m_dimensions.radius, 2) + pow(m_dimensions.height, 2));
	double surfaceArea = PI * (m_dimensions.radius * (m_dimensions.radius + slantHeight));
	return surfaceArea;
}

const std::string& Cone::getTypeName() const
{
	return m_type;
}

void Cone::setDimensions(double height, double radius)
{
	m_dimensions.height = height;
	m_dimensions.radius = radius;
}

const Dimensions& Cone::getDimensions() const
{
	return m_dimensions;
}

Cone::~Cone()
{}

