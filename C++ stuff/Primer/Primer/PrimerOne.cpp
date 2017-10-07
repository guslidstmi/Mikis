#include <iostream>
#include "PrimerOne.h"

PrimerOne::PrimerOne()
{}

void PrimerOne::Output()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1;
	std::cout << " and " << v2;
	std::cout << " is " << v1 + v2 << std::endl;
}

void PrimerOne::Greetings()
{
	std::cout << "Hello, World" << std::endl;
}

void PrimerOne::multiplication()
{
	std::cout << "Enter two numbers:" << std::endl;
	int i, j;
	std::cin >> i >> j;
	std::cout << "The product of " << i << " and " << j << " is " << i * j << std::endl;
}

void PrimerOne::sum(int i, int j)
{
	if (i > j)
	{
		int temp = i;
		i = j;
		j = temp;
	}
	int sum = 0;
	while (i <= j)
	{
		sum += i;
		++i;
	}

	std::cout << "sum of all numbers is: " << sum << std::endl;

}
