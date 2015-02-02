#include <stdio.h>

int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);
void printArray(int tab[]);
int test[] = {1,2,3,34,5,67,3,23,12,13,10};

int main(void)
{
	int number = 34;
	int index = -1;

	if((index = search_number(number, test, (int) sizeof(test)/sizeof(test[0]))) == -1)
	{
		printf("%d is not in the array\n", number);
	}
	else
		printf("%d is on index number %d\n", number, index);

	printf("Before sorting: ");
	printArray(test);

	sort(0, test);
}

int search_number(int number, int tab[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		if(number == tab[i])
			return i;
	}

	return -1;
}

void sort(int number, int tab[])
{
	for(int i = number; i < (int) sizeof(test)/sizeof(test[0]); ++i)
	{
		int smallest = tab[number];
		int index = 0;
		for(int j = number; j < (int) sizeof(test)/sizeof(test[0]); ++j)
		{
			if(tab[j] < smallest)
			{
				smallest = tab[j];
				index = j;
				tab[index] = tab[i];
				tab[i] = smallest;
			}
		}
		++number;
	}
	printf("After sorting: "); 
	printArray(tab);
}

void printArray(int tab[])
{
	for(int i = 0; i < (int) sizeof(test)/sizeof(test[0]); ++i)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}