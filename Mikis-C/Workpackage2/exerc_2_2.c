#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX 20

int main(int argc, char *argv[])
{

	int numbers[MAX];
	srand(time(NULL));

	for(int i = 0; i < MAX; ++i)
	{
		int random = rand() % 100;
		numbers[i] = random;
		printf("%d\n", random);
	}

	printf("Adress of array: %p\n", &numbers);
	printf("First integer of array: %d\n", numbers[0]);
	printf("Size of an integer: %zu, Size of array: %zu\n", 
		sizeof(numbers[0]), sizeof(numbers));

	for(int i = 0; i < MAX; ++i)
	{
		numbers[i] += numbers[i];
		printf("%d\n", numbers[i]);
	}

	return 0;
}