#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *tab);
void count_frequncy(int *tab, int *freq);
void draw_histogram(int *freq);

int main(void)
{
	int table[MAX];
	int frequency[MAXNUMBER];
	create_random(table);
	count_frequncy(table, frequency);
	draw_histogram(frequency);

}

void create_random(int *tab)
{
	srand(time(NULL));
	for(int i = 0; i < MAX; ++i)
	{
		*(tab+i) = random() % MAXNUMBER;
		//Uncomment to see the random numbers.
		//printf("%d  %d\n", i, *(tab+i));
	}
}

void count_frequncy(int *tab, int *freq)
{
	for(int i = 0; i < MAXNUMBER; ++i)
	{
		int count = 0;
		for(int j = 0; j < MAX; ++j)
		{
			if(*(tab+j) == i)
			{
				++count;
			}
		}
		*(freq+i) = count;
		// Uncomment to see how many of each random number.
		//printf("%d  %d\n", i, *(freq+i));
	}

}

void draw_histogram(int *freq)
{
	for(int i = 0; i < MAXNUMBER; ++i)
	{
		if(*(freq+i) > 0)
		{
			printf("%d  ", i);
			for(int j = 0; j <= *(freq+i); ++j)
			{
				printf("%c", 'x');	
			}
			printf("\n");
			
		}
	}
}