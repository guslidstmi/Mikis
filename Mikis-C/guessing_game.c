#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void flushstdin();
void start();

int main(int argc, char *argv[])
{
	int play = 1;
	printf("hello\n");
	
	while(play)
	{
		start();

		printf("Do you want to play again?(y=1/n=0)");
		scanf("%d", &play);
		if(play == 1)
		{
			printf("Playing again!\n");
		}
		else 
		{
			printf("Stopping!");
		}
		
	}
	return 0;	
}

void start()
{
	int guess, guesses = 0;
	srand(time(NULL));
	int random =  rand() %100;
	//printf("%d\n", random);

	while(guess != random)
	{
		printf("Guess a number\n");
		scanf("%d", &guess);
		flushstdin();
		
		if(guess > random && guess < 100)
		{
			printf("Too High! Guess again.\n");
			++guesses;
		}
		else if(guess < random && guess > 0)
		{
			printf("Too Low! Guess again.\n");
			++guesses;
		}
		else if (guess == random)
		{
			++guesses;
			printf("Correct!\nYou had %d guesses\n", guesses);
		}
		else
			printf("Please enter a real number.\n");
	}
}

void flushstdin()
{
	char ch;
	while((ch = getchar()) != '\n');
}