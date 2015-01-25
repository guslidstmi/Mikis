#include <stdio.h>

int main(int argc, char *argv[]){
	char input;

	char *sentences[] = {"Sentence 1", "Sentence 2", "Sentence 3", 
	"Sentence 4", "Sentence 5", "Sentence 6", "Sentence 7", 
	"Sentence 8", "Sentence 9"};

	printf("Enter a number.\n");
	while((input = getchar()) != '0'){
		if(input >= '1' && input <= '9')
		printf("%s\n", sentences[input -'1']);
	}
	return 0;
}