#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <set>

int factorial(unsigned long);
int findAllSet(std::string, std::string, int, int);
void pairUp(std::map<int, std::vector<std::vector<bool>>>&,
	std::string, std::string, std::string);

int main()
{
	int number_of_switches = 0, number_of_photos = 0;

	std::cin >> number_of_switches >> number_of_photos;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	if (number_of_photos > 0)
	{
		std::string switches = "", lights = "";
		int setSwitches  = 0, setLights = 0, unSetSwitches = 0, 
			unSetLights = 0, tempSets = 0, tempZeros = 0;
		std::map<int, std::vector<std::vector<bool>>> setMap, zeroMap;
		for (int i = 0; i < number_of_photos * 2; ++i)
		{
			if (i % 2 == 0)
			{
				std::getline(std::cin, switches);
			}
			else
			{
				std::getline(std::cin, lights);

				setSwitches = findAllSet(switches, "1", 0, 0);
				setLights = findAllSet(lights, "1", 0, 0);

				if (setSwitches != setLights)
				{
					std::cout << 0 << "\n";
					return 0;
				}
				pairUp(setMap, switches, lights, "1");
				//pairUp(zeroMap, switches, lights, "0");
			}
		}

		for (auto& map : setMap)
		{
			for (std::vector<bool> vector : map.second)
			{
				for(const bool& b : vector)
				{
					std::cout <<  b;
				}

				std::cout << "\n";
			}
		}

		//std::cout << factorial(tempSets) * factorial(tempZeros) << "\n";
	}
	else
	{
		std::cout << factorial(number_of_switches) << "\n";
	}

	system("pause");
	return 0;
}

int factorial(unsigned long num)
{
	if (num == 1 || num == 0)
	{
		return 1;
	}
	return factorial(num - 1) * num % 1000003;
}

int findAllSet(std::string s, std::string c, int position, int num)
{
	int result = s.find(c, position);
	if (result == std::string::npos)
	{
		return num;
	}

	++num;
	return findAllSet(s, c, ++result, num % 1000003);
}
void pairUp(std::map<int, std::vector<std::vector<bool>>>& setMap, 
	std::string switches, std::string lights, std::string c)
{
	int position = 0, result = 0;
	while (result != std::string::npos)
	{
		result = switches.find(c, result);
		if(result >= 0)
		{
			std::cout << "Hai: " << result << std::endl;
			std::vector<bool> tempVect(lights.length(), 0);
			position = lights.find(c, position);
			tempVect[position] = 1;
			std::cout << "tempVect " << tempVect[position] << std::endl;
			setMap[result].push_back(tempVect);
			++position;
			++result;
		}
		
	}
	std::cout<< "Leaving pairup" << std::endl;
}
