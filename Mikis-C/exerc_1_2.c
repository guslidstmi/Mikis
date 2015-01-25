#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

int main(int argc, char *argv[]) {
	printf("Enter a Sentence\n");
	
	char input[MAX];

	fgets(input, MAX, stdin);

	printf("%s\n", input);
	int len = strlen(input);
	//if(len > 0 && input[len-1] == '\n')
	//	input[len-1] = '\0';

	int words = 0;
	for(int i = 0; i < len; i++)
	{
		if(isspace(input[i])){
			++words;
		}
	}
	printf("This sentence has %d words\n", words);

	return 0;
}