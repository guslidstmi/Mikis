#include "TestHarness.h"
#include <iostream>
#include <memory>
#include <cmath>

TestHarness::TestHarness() :
	factory{}
{}

const bool TestHarness::runTests()
{
	if (!testCone() || !testCuboid() || !testSphere())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool TestHarness::testCone()
{
	double height = 2.0;
	double radius = 4.0;
	std::unique_ptr<Cone> cone = factory.createCone(height, radius);
	if (cone->getTypeName().compare("Cone") != 0)
	{
		std::cout << "Type does not match, test failed" << std::endl;
		return false;
	}
	else if (cone->getVolume() != coneVol(height, radius))
	{
		std::cout << "volume of the cone does not match, test failed" << std::endl;
		return false;
	}
	else if(cone->getSurface() != coneSurf(height, radius))
	{
		std::cout << "surface area of the cone does not match, test failed" << std::endl;
		return false;
	}
	else if (!(Colour(255, 255, 255) == cone->getColour()))
	{
		std::cout << "Colour of the cone does not match, test failed" << std::endl;
		return false;
	}
	else if ((cone->getDimensions().height != 2.0) && (cone->getDimensions().radius != 4.0))
	{
		std::cout << "Dimensions of the cone do not match, test failed" << std::endl;
		return false;
	}
	std::cout << "Setting new colour for Cone" << std::endl;
	cone->setColour(135, 125, 11);
	if (!(Colour(135, 125, 11) == cone->getColour()))
	{
		std::cout << "Colour of the cone does not match the new colour" << std::endl;
	}

	std::cout << "setting new dimensions for Cone" << std::endl;
	cone->setDimensions(3.0, 5.0);
	std::cout << cone->getVolume() << std::endl;
	if ((cone->getDimensions().height != 3.0) && (cone->getDimensions().radius != 5.0))
	{
		std::cout << "Dimensions of the cone do not match, test failed" << std::endl;
		return false;
	}
	else if (cone->getVolume() == coneVol(height, radius))
	{
		std::cout << "Volume of the new dimensions of the cone matches the old dimensions, test failed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "tests passed for Cone" << std::endl;
		return true;
	}
}

bool TestHarness::testCuboid()
{
	double length = 2.0;
	double height = 2.0;
	double depth = 4.0;
	std::unique_ptr<Cuboid> cuboid = factory.createCuboid(length, height, depth);
	if (cuboid->getTypeName().compare("Cuboid") != 0)
	{
		std::cout << "Type does not match, test failed" << std::endl;
		return false;
	}
	else if (cuboid->getVolume() != cuboidVol(length, height, depth))
	{
		std::cout << "volume of the cuboid does not match, test failed" << std::endl;
		return false;
	}
	else if (cuboid->getSurface() != cuboidSurf(length, height, depth))
	{
		std::cout << "surface area of the cuboid does not match, test failed" << std::endl;
		return false;
	}
	else if (!(Colour(255, 255, 255) == cuboid->getColour()))
	{
		std::cout << "Colour of the cuboid does not match, test failed" << std::endl;
		return false;
	}
	else if ((cuboid->getDimensions().length != 2.0) && 
		(cuboid->getDimensions().height != 2.0) && (cuboid->getDimensions().depth != 4.0))
	{
		std::cout << "Dimensions of the cuboid do not match, test failed" << std::endl;
		return false;
	}
	std::cout << "Setting new colour for Cuboid" << std::endl;
	cuboid->setColour(135, 125, 11);
	if (!(Colour(135, 125, 11) == cuboid->getColour()))
	{
		std::cout << "Colour of the cuboid does not match the new colour" << std::endl;
	}

	std::cout << "setting new dimensions for Cuboid" << std::endl;
	cuboid->setDimensions(3.0, 5.0, 2.5);
	if ((cuboid->getDimensions().length != 3.0) &&
		(cuboid->getDimensions().height != 5.0) && (cuboid->getDimensions().depth != 2.5))
	{
		std::cout << "Dimensions of the cuboid do not match, test failed" << std::endl;
		return false;
	}
	else if (cuboid->getVolume() == cuboidVol(length, height, depth))
	{
		std::cout << "Volume of the new dimensions for the cuboid matches the old dimensions, test failed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "tests passed for Cuboid" << std::endl;
		return true;
	}
}

bool TestHarness::testSphere()
{
	double radius = 2.0;
	std::unique_ptr<Sphere> sphere = factory.createSphere(radius);
	if (sphere->getTypeName().compare("Sphere") != 0)
	{
		std::cout << "Type does not match, test failed" << std::endl;
		return false;
	}
	else if (sphere->getVolume() != SphereVol(radius))
	{
		std::cout << "volume of the sphere does not match, test failed" << std::endl;
		return false;
	}
	else if (sphere->getSurface() != SphereSurf(radius))
	{
		std::cout << "surface area of the sphere does not match, test failed" << std::endl;
		return false;
	}
	else if (!(Colour(255, 255, 255) == sphere->getColour()))
	{
		std::cout << "Colour of the sphere does not match, test failed" << std::endl;
		return false;
	}
	else if (sphere->getDimensions().radius != 2.0)
	{
		std::cout << "Dimensions of the sphere do not match, test failed" << std::endl;
		return false;
	}
	std::cout << "Setting new colour for Sphere" << std::endl;
	sphere->setColour(220, 111, 125);
	if (!(Colour(220, 111, 125) == sphere->getColour()))
	{
		std::cout << "Colour of the sphere does not match the new colour" << std::endl;
	}

	std::cout << "setting new dimensions for Sphere" << std::endl;
	sphere->setDimensions(4.0);
	if (sphere->getDimensions().radius != 4.0)
	{
		std::cout << "Dimensions of the sphere do not match, test failed" << std::endl;
		return false;
	}
	else if (sphere->getVolume() == SphereVol(radius))
	{
		std::cout << "Volume of the new dimensions of the sphere matches the old dimensions, test failed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "tests passed for Sphere" << std::endl;
		return true;
	}
}

double TestHarness::coneVol(double h, double r)
{
	return (1.0 / 3.0) * ((PI * pow(r, 2)) * h);
}

double TestHarness::coneSurf(double h, double r)
{
	return PI * (r * (r + sqrt(pow(r, 2) + pow(h, 2))));
}

double TestHarness::cuboidVol(double l, double h, double d)
{
	return l * h * d;
}

double TestHarness::cuboidSurf(double l, double h, double d)
{
	return (l * h) + (l * d) + (d * h);
}

double TestHarness::SphereVol(double r)
{
	return (4.0 / 3.0) * (PI * pow(r, 3));
}

double TestHarness::SphereSurf(double r)
{
	return 4 * (PI * pow(r, 2));
}


