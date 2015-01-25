#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	int count = 0;
	char word[10];
	while((c = getchar()) != EOF)
	{
		printf("%d\n", c);
		if((c > 64 && c <= 77) || (c > 96 && c <= 109 )) 
		{
			word[count] = c + 13;
			++count;

		}
		else if((c > 77 && c <= 90) || (c > 109 && c <= 122 ))
		{
			word[count] = c - 13;
			++count;
		}
		else if(c == '\n')
		{
			printf("%s\n", word);
			count = 0;
			memset(&word[0], '\0', sizeof(word));
		}
	}
}