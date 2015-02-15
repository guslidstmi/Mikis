#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	unsigned char brake2 : 1;
	unsigned char brake1 : 1;
	unsigned char key_pos : 2;
	unsigned char gear_pos : 3;
	unsigned char engine_on : 1;

} BYTE;

int main(int argc, char *argv[])
{
	if(argc != 2 || strlen(argv[1]) > 2)
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