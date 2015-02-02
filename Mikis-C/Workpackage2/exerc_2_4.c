#include <stdio.h>
#include <string.h>

#define MAX 20

int main(int argc, char *argv[])
{
	char palin[MAX];
	int truth = 1;
	fgets(palin, MAX, stdin);

	if(palin[strlen(palin)-1] == '\n')
	{
		palin[strlen(palin)-1] = '\0';
	}

	for(int i = 0, j = strlen(palin) -1; j >= i; ++i, --j)
	{
		if(palin[i] != palin[j])
		{
			truth = 0;
		}
	}

	if(truth == 0){
		printf("%s is not a palindrome\n", palin);
	}
	else
		printf("%s is a palindrome!\n", palin);

}
