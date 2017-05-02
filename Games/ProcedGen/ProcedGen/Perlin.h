#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

class Perlin
{
public:

	Perlin(int height, int width);
	double noise(double x, double y, double z);
	double fade(double t);
	double interpolation(double t, double a, double b);
	double gradient(int hash, double x, double y, double z);

	double generatePerlin(double x, double y, double z, int octaves, double persistence);

private :
	int m_height;
	int m_width;
	double m_grid[200][200];
	std::vector<int> m_permutation;
};
