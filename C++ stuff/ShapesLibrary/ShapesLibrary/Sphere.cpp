#include "Sphere.h"
#include <cmath>

Sphere::Sphere(double radius) 
	: m_dimensions{0, 0, 0, radius}
	, m_type{"Sphere"}
{}

double Sphere::getVolume() const
{
	double volume = (4.0/3.0) * (PI * pow(m_dimensions.radius, 3));
	return volume;
}

double Sphere::getSurface() const
{
	double surfaceArea = 4 * (PI * pow(m_dimensions.radius, 2));
	return surfaceArea;
}

const std::string& Sphere::getTypeName() const
{
	return m_type;
}

const void Sphere::setDimensions(double radius)
{
	m_dimensions.radius = radius;
}

const Dimensions& Sphere::getDimensions() const
{
	return m_dimensions;
}

Sphere::~Sphere()
{}


