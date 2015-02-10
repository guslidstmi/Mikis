/*===================================
File name: exerc_3_2.c 
Date: 2015-02-10
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#include <stdio.h>

/*
/ Function which checks if the number exists in the array.
/ In: int number to be checked, int array, int size of array.
/ Out: index of the number in the array or -1 if number does not exist.
*/
int search_number(int number, int tab[], int size);

/*
/ Function for sorting the array by finding minimum value and swapping with the first value. 
/ After swapping the first value, first value changes to be the next element in the array.
/ In: int number = starting index. int array which is being sorted.
*/
void sort(int number, int tab[]);

/*
/ Function for printing the values in the array.
/ In: int array to be printed.
*/
void printArray(int tab[]);

// premade array.
int test[] = {1,2,3,34,5,67,3,23,12,13,10};

int main(void)
{
	int number = 34; // number to be looked for.
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
	int i;
	for(i = 0; i < size; ++i)
	{
		if(number == tab[i])
			return i;
	}

	return -1;
}

void sort(int number, int tab[])
{
	int i, j;
	for(i = number; i < (int) sizeof(test)/sizeof(test[0]); ++i)
	{
		int smallest = tab[number];
		int index = 0;
		for(j = number; j < (int) sizeof(test)/sizeof(test[0]); ++j)
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
	int i;
	for(i = 0; i < (int) sizeof(test)/sizeof(test[0]); ++i)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}