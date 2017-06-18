#pragma once
#include "Factory.h"

class TestHarness
{
public:
	TestHarness();
	const bool runTests();

private :
	Factory factory;
	bool testCone();
	bool testCuboid();
	bool testSphere();
	double coneVol(double h, double r);
	double coneSurf(double h, double r);
	double cuboidVol(double l, double h, double d);
	double cuboidSurf(double l, double h, double d);
	double SphereVol(double r);
	double SphereSurf(double r);

};