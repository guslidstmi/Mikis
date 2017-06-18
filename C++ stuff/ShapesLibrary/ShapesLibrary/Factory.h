#pragma once
#include "Cone.h"
#include "Cuboid.h"
#include "Sphere.h"
#include <memory>

class Factory 
{
public:
	Factory();
	std::unique_ptr<Cone> createCone(double height, double radius);
	std::unique_ptr<Cuboid> createCuboid(double length, double height, double depth);
	std::unique_ptr<Sphere> createSphere(double radius);
};