/*===================================
File name: exerc_3_1.c 
Date: 2015-02-10
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/


#include <stdio.h>

#define MAX 20

enum DIRECTION {N,E,S,W};

typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

/*
/ Function for moving the robots x and y position.
/ In: Robot pointer.
*/
void move(ROBOT *robot);

/*
/ Function for turning the robot clockwise.
/ In: Robot pointer.
*/
void turn(ROBOT *robot);

/*
/ Function for clearing stdin.
*/
void flushstdin();

int main(void)
{
	ROBOT robot;
	
	char input[MAX];
	char again;
	while(again != 'n')
	{
		robot.dir = N; // Starting direction
		printf("Enter x starting position for the Robot: ");
		scanf("%d", &robot.xpos);
		printf("Enter y starting position for the Robot: ");
		scanf("%d", &robot.ypos);
		printf("Enter a move sequence for the robot(t or m): ");
		scanf("%s", input);

		// Iterates through the move sequence.
		for(int i = 0; i < sizeof(input); ++i)
		{
			if(input[i] == 'm')
			{
				move(&robot);
			}
			
			else if(input[i] == 't')
			{
				turn(&robot);
			}
		}
		printf("Robot position is: %d,%d and direction is %d\n", 
		robot.xpos, robot.ypos, robot.dir);	

		flushstdin();

		printf("Want to go again? (y/n)\n");
		scanf("%c", &again);
	}
}

void move(ROBOT *robot)
{
	if(robot->dir == 0)
		robot->ypos++;
	else if(robot->dir == 1)
		robot->xpos++;
	else if(robot->dir == 2)
		robot->ypos--;
	else
		robot->xpos--;
}

void turn(ROBOT *robot)
{
	if(robot->dir == 3)
		robot->dir = 0;
	else
		robot->dir++;
}

void flushstdin()
{
	char ch;
	while((ch = getchar()) != '\n');
}