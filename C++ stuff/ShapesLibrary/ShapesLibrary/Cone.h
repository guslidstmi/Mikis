#pragma once
#include "Shape.h"

class Cone : public Shape 
{

public:
	Cone(double height, double radius);
	double getVolume() const override;
	double getSurface() const override;
	const std::string& getTypeName() const override;
	void setDimensions(double height, double radius);
	const Dimensions& getDimensions() const override;
	~Cone();

private:

	Dimensions m_dimensions;
	std::string m_type;
};