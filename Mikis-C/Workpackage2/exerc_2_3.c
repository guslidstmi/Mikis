#include <stdio.h>
#include <string.h>

#define MAX 30

int compare(char *p1, char *p2);

int main(int argc, char *argv[])
{

	if(strcmp(argv[1], argv[2]) == 0)
	{
		printf("The strings are identical. (strcmp)\n");
	}
	else
		printf("The strings are not identical. (strcmp)\n");

	if(compare(argv[1], argv[2]) == 0)
	{
		printf("The strings are identical. (my compare)\n");
	}
	else
		printf("The strings are not identical. (my compare)\n");

}

int compare(char *p1, char *p2)
{
	int result;
	for(int i = 0; *(p1+i) != '\0'; ++i)
	{
		if(*(p1+i) != *(p2+i))
		{
			result = 1;
		}
		else
			result = 0;
	}
	return result;
}
