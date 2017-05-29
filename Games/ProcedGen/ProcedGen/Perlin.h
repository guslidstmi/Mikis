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

	Perlin(const int height, const int width);
	const double generatePerlin(const double x, const double y, const double z, const int octaves, const double persistence);

private :
	const double noise(double x, double y, double z);
	const double fade(const double t);
	const double interpolation(const double t, const double a, const double b);
	const double gradient(const int hash, const double x, const double y, const double z);

	int m_height;
	int m_width;
	double m_grid[200][200];
	std::vector<int> m_permutation;
};
