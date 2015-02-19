/*===================================
File name: decode.c
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
#include <stdlib.h>

// structure for 8 bit struct
typedef struct {
	unsigned char brake2 : 1;
	unsigned char brake1 : 1;
	unsigned char key_pos : 2;
	unsigned char gear_pos : 3;
	unsigned char engine_on : 1;

} BYTE;

/*
* if argument is not 2, length of argument is bigger than 2 
* and if the argument is bigger than hexdec CB, return error.
* convert argument to long.
* Assign first bit in input to brake2, bitswitch assigned position.
* Repeat for the rest of the input.
* IN: hexdecimal. OUT: 0
*/
int main(int argc, char *argv[])
{	
	// checks if 2 arguments, 
	if(argc != 2 || strlen(argv[1]) > 2 || strtol(argv[1], NULL, 16) > 203)
	{
		printf("error\n");
		return 1;
	}
	BYTE byte;
	unsigned char input = strtol(argv[1], NULL, 16);

	byte.brake2 = input & 1;
	input = input >> 1;
	byte.brake1 = input & 1;
	input = input >> 1;
	byte.key_pos = input & 2;
	input = input >> 2;
	byte.gear_pos = input & 3;
	input = input >> 3;
	byte.engine_on = input & 1;

	printf("Name\tValue\n");
	printf("%s", "-------------\n");
	printf("engine on %d\n", byte.engine_on);
	printf("gear_pos  %d\n", byte.gear_pos);
	printf("key_pos\t  %d\n", byte.key_pos);
	printf("brake1\t  %d\n", byte.brake1);
	printf("brake2\t  %d\n", byte.brake2);




}