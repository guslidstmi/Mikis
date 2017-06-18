#include "Factory.h"

Factory::Factory()
{
}

std::unique_ptr<Cone> Factory::createCone(double height, double radius)
{
	return std::make_unique<Cone>(height, radius);
}

std::unique_ptr<Cuboid> Factory::createCuboid(double length, double height, double depth)
{
	return std::make_unique<Cuboid>(length, height, depth);
}

std::unique_ptr<Sphere> Factory::createSphere(double radius)
{
	return std::make_unique<Sphere>(radius);
}
