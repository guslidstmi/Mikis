#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <bitset>

int factorial(int);

int main()
{
	int number_of_switches = 0;
	int number_of_photos = 0;

	std::cin >> number_of_switches >> number_of_photos;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::bitset<1000> wirings = std::bitset<1000>().set();
	
	
	if (number_of_photos > 0)
	{
		std::vector<std::bitset<1000>> switches(number_of_photos);
		std::vector<std::bitset<1000>> lights(number_of_photos);
		for (int j = 0, i = 0; i < number_of_photos * 2; ++i)
		{
			if (i % 2 == 0)
			{
				std::string stringSwitch = "";
				std::getline(std::cin, stringSwitch);
				switches[j] = std::bitset<1000>(stringSwitch);
			}
			else
			{
				std::string stringLight = "";
				std::getline(std::cin, stringLight);
				lights[j] = std::bitset<1000>(stringLight);
				++j;
			}
		}

		for (int i = 0; i < number_of_photos; ++i)
		{
			wirings &= (switches[i] & lights[i]);
		}
		std::cout << "wirings bit " << wirings.to_ullong() << "\n";

	}
	else
	{
		std::cout << factorial(number_of_switches) << "\n";
	}

	system("pause");
	return 0;
}

int factorial(int num)
{
	if (num == 1)
	{
		return num;
	}
	return factorial(num - 1) * num % 1000003;
}
