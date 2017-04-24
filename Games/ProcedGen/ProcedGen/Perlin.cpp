#include "Perlin.h"

Perlin::Perlin(int height, int width) :
	m_height{ height }
	, m_width{ width }
{}

void Perlin::perlin()
{
	generateNoise();
	for ( int y = 0; y < m_height; ++y )
	{
		for ( int x = 0; x < m_width; ++x )
		{
			m_grid[x][y] = turbulence( x, y, 16 ) / 4;
		}
	}
}

void Perlin::generateNoise()
{
	std::random_device rd;
	std::default_random_engine generator( rd() );
	std::normal_distribution<double> distribution( 0.5, 0.5 );

	for ( int y = 0; y < m_height; ++y )
	{
		for ( int x = 0; x < m_width; ++x )
		{
			m_grid[y][x] = distribution( generator );
		}
	}
}

double Perlin::smoothNoise(double x, double y)
{
	double fractX = x - int( x );
	double fractY = y - int( y );

	int x1 = ( int( x ) + m_width ) % m_width;
	int y1 = ( int( y ) + m_height ) % m_height;

	int x2 = ( x1 + m_width - 1 ) % m_width;
	int y2 = ( y1 + m_height - 1 ) % m_height;

	double value = 0.0;
	value += fractX * fractY * m_grid[y1][x1];
	value += ( 1 - fractX ) * fractY * m_grid[y1][x2];
	value += fractX * ( 1 - fractY ) * m_grid[y2][x1];
	value += ( 1 - fractX ) * ( 1 - fractY ) * m_grid[y2][x2];

	return value;
}

double Perlin::turbulence(double x, double y, double size)
{
	double value = 0.0, initialSize = size;
	
	while ( size >= 1 )
	{
		value += smoothNoise( x / size, y / size ) * size;
		size /= 2.0;
	}
	return (value/initialSize);
}

double Perlin::getGridValueByIndex(int x, int y)
{
	return m_grid[x][y];
}
