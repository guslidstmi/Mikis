#include <stdio.h>

#define MAX 20

enum DIRECTION {N,E,S,W};

typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot);
void turn(ROBOT *robot);
void flushstdin();

int main(void)
{
	ROBOT robot;
	
	char input[MAX];
	char again;
	while(again != 'n')
	{
		robot.dir = N;
		printf("Enter a move sequence for the robot(t or m): ");
		scanf("%s", input);
		printf("Enter x starting position for the Robot: ");
		scanf("%d", &robot.xpos);
		printf("Enter y starting position for the Robot: ");
		scanf("%d", &robot.ypos);

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