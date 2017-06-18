#pragma once
#include "Shape.h"

class Cuboid : public Shape {

public :
	Cuboid(double length, double height, double depth);
	double getVolume() const override;
	double getSurface() const override;
	const std::string& getTypeName() const override;
	void setDimensions(double length, double height, double depth);
	const Dimensions& getDimensions() const override;
	~Cuboid();

private:

	Dimensions m_dimensions;
	std::string m_type;
};