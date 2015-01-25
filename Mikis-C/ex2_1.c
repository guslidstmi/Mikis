#include <stdio.h>
#include <string.h>

#define MAX 20

void copyString(char *p1, char *p2);

int main(int argc, char *argv[])
{
	char str[MAX], copy[MAX], copy2[MAX];
	char *p1 = str;
	char *p2 = copy2;

	fgets(str, MAX, stdin);

	strcpy(copy, str);
	printf("%s\n", copy);
	copyString(p1, p2);
	printf("%s\n", copy2);
}

void copyString(char *p1, char *p2)
{
	
	for(int i = 0; *(p1+i) != '\0'; ++i)
	{
		*(p2+i) = *(p1+i);
	}
}