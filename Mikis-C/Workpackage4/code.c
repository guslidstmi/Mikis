/*===================================
File name: code.c
Date: 2015-02-15
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#include <stdio.h>
#include <string.h>

/*
* if argument is not 6, length of argument is bigger than 1 
* and if the arguments are not within a certain range of numbers. return error.
* bitswitch first number, convert to int, to the right position, take second number, 
* convert to int, and switch it to right position
* perfom "bit-or" to merge them. repeat.
* IN: 6 numbers. OUT: 0
*/
int main(int argc, char *argv[])
{
	if(argc != 6)
	{
		printf("error\n");
		return 1;
	}
	int i;

	for(i = 1; i < 6; ++i)
	{
		if(strlen(argv[i]) > 1)
		{
			printf("Invalid length of argument %d\n", i);
			return 1;
		}
	}

	unsigned char byte;
	if(*argv[1] >= 48 && *argv[1] <= 49 
        && *argv[2] >= 48 && *argv[2] <= 52
        && *argv[3] >= 48 && *argv[3] <= 50
        && *argv[4] >= 48 && *argv[4] <= 49
        && *argv[5] >= 48 && *argv[5] <= 49)
	{
		byte = (*argv[1] - '0') << 7;
		byte = byte | (*argv[2] - '0') << 4;
		byte = byte | (*argv[3] - '0') << 2;
		byte = byte | (*argv[4] - '0') << 1;
		byte = byte | (*argv[5] - '0');
	}
	else
	{
		printf("error\n");
		return 1;
	}

	printf("%x\n", byte);

	return 0;

}