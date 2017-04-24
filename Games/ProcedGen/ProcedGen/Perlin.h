#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>

class Perlin
{
public:

	Perlin(int height, int width);
	void perlin();
	void generateNoise();
	double smoothNoise(double x, double y);
	double turbulence( double x, double y, double size );
	double getGridValueByIndex(int x, int y);

private :
	int m_height;
	int m_width;
	double m_grid[200][200];
};
