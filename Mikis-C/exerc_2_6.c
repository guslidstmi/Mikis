#include <stdio.h>


#define MAX 5

int input(int *list, int number);
void initQue(int *list);

int main(void)
{
	int queue[MAX];
	int number = 4;
	initQue(queue);
	if(input(queue, number) == 1)
		{
			printf("The number was inputed correctly\n");
		}
	else
	printf("The number was not inputed");
	number = 5;
	if(input(queue, number) == 1)
		{
			printf("The number was inputed correctly\n");
		}
	else
		printf("The number was not inputed\n");
	number = 3;
	if(input(queue, number) == 1)
		{
			printf("The number was inputed correctly\n");
		}
	else
		printf("The number was not inputed\n");
	number = 8;
	if(input(queue, number) == 1)
		{
			printf("The number was inputed correctly\n");
		}
	else
		printf("The number was not inputed\n");

	for(int i = 0; i < MAX; ++i)
	{
		printf("%d", queue[i]);
	}
	printf("\n");

}

int input(int *list, int number)
{
	printf("%d\n", *(list+(MAX -1)));
	if(*(list+(MAX-1)) == -1)
	{
		for(int i = 0; i < MAX; ++i)
		{
			if(*(list+i) == -1)
			{
				*(list+i) = number;
				return 1;
			}
		}
	}

	return 0;
}

void initQue(int *list)
{
	for(int i = 0; i < MAX; ++i)
	{
		*(list+i) = -1;
		printf("%d\n", *(list+i));
	}
}