
#include "Sales_item.h"
#include <iostream>
#include <fstream>
#include <string>

void readFrom(int num, std::ifstream& myfile)
{
	int row = 1;
	std::string line;
	while (getline(myfile, line))
	{
		if (row >= num)
		{
			std::cout << line << "\n";
		}
		++row;
	}
}

int main()
{
	
	std::ifstream myfile ("data/input.txt");

	if (myfile.is_open())
	{
		readFrom(5, myfile);
	}


	return 0;
}