#include "TestHarness.h"
#include <iostream>
int main()
{
	TestHarness test;
	if (test.runTests() != true)
	{
		std::cout << "Test failed" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "All Tests passed!" << std::endl;
		return 0;
	}

}