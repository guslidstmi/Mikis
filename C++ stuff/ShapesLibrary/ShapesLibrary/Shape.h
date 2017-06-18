#pragma once
#include <string>
#include <iostream>

struct Colour
{
	Colour(int r, int g, int b) 
		: R{r}
		, G{g}
		, B{b}
	{}

	int R;
	int G;
	int B;

	bool operator== (const Colour& col)
	{
		return (R == col.R) && (G == col.G) && (B == col.B);
	}
};

struct Dimensions
{
	Dimensions(double l, double h, double d, double r) :
		length{ l }
		, height{ h }
		, depth{d}
		, radius{r}
	{}
	double length;
	double height;
	double depth;
	double radius;

	bool operator== (const Dimensions& dim)
	{
		return (length == dim.length) && (height == dim.height) && (depth == dim.depth) && (radius == dim.radius);
	}
};

namespace 
{
	constexpr double PI = 3.14159265359;
}

class Shape 
{

public:
	Shape();
	virtual double getVolume() const = 0;
	virtual double getSurface() const = 0;
	virtual const std::string& getTypeName() const = 0;
	virtual const Dimensions& getDimensions() const = 0;
	const void setColour(int r, int g, int b);
	const Colour& getColour() const;

	template<typename T>
	T* Shape::getType()
	{
		return dynamic_cast<T*>(this);
	}

	virtual ~Shape();
	
private:
	Colour m_colour;
};


