#include "Perlin.h"

Perlin::Perlin(const int height, const int width) :
	m_height{ height }
	, m_width{ width }
{
	m_permutation.resize(256);
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::iota(m_permutation.begin(), m_permutation.end(), 0);

	std::shuffle(m_permutation.begin(), m_permutation.end(), generator);

	m_permutation.insert(m_permutation.end(), m_permutation.begin(), m_permutation.end());
}

const double Perlin::noise(double x, double y, double z)
{
	int newX = (int)floor(x) & 255;
	int newY = (int)floor(y) & 255;
	int newZ = (int)floor(z) & 255;

	x -= floor(x);
	y -= floor(y);
	z -= floor(z);

	double u = fade(x);
	double v = fade(y);
	double w = fade(z);

	int a = m_permutation[newX] + newY;
	int aa = m_permutation[a] + newZ;
	int ab = m_permutation[a + 1] + newZ;
	int b = m_permutation[newX + 1] + newY;
	int ba = m_permutation[b] + newZ;
	int bb = m_permutation[b + 1] + newZ;

	double result = interpolation(w, interpolation(v, interpolation(u, gradient(m_permutation[aa], x, y, z), gradient(m_permutation[ba], x - 1, y, z)), 
		interpolation(u, gradient(m_permutation[ab], x, y - 1, z), gradient(m_permutation[bb], x - 1, y - 1, z))), 
		interpolation(v, interpolation(u, gradient(m_permutation[aa + 1], x, y, z - 1), gradient(m_permutation[ba + 1], x - 1, y, z - 1)), 
		interpolation(u, gradient(m_permutation[ab + 1], x, y - 1, z - 1), gradient(m_permutation[bb + 1], x - 1, y - 1, z - 1))));

	return (result + 1.0)/2.0;
}

const double Perlin::fade(const double t) 
{
	// f(t) = 6t^5 - 15t^4 + 10t^3
	return t * t * t * (t * (t * 6 - 15) + 10); 
}

const double Perlin::interpolation(const double t, const double a, const double b) 
{
	return a + t * (b - a);
}

const double Perlin::gradient(const int hash, const double x, const double y, const double z) 
{
	int h = hash & 15;
	// Convert lower 4 bits of hash into 12 gradient directions
	double u = h < 8 ? x : y,
		v = h < 4 ? y : h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

const double Perlin::generatePerlin(const double x, const double y, const double z, const int octaves, const double persistence) 
{
	double total = 0.0;
	double frequency = 0.007;
	double amplitude = 1.0;
	double maxValue = 0.0;  // Used for normalizing result to 0.0 - 1.0
	for (int i = 0; i<octaves; i++) {
		total += noise(x * frequency, y * frequency, z * frequency) * amplitude;

		maxValue += amplitude;

		amplitude *= persistence;
		frequency *= 2;
	}

	return total / maxValue;
}

