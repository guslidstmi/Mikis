#pragma once
#include "Shape.h"

class Sphere : public Shape 
{

public:
	Sphere(double radius);
	double getVolume() const override;
	double getSurface() const override;
	const std::string& getTypeName() const override;
	const void setDimensions(double radius);
	const Dimensions& getDimensions() const override;
	~Sphere();

private:

	Dimensions m_dimensions;
	std::string m_type;
};