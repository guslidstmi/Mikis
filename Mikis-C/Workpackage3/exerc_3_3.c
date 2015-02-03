/*===================================
File name: exerc_3_3.c 
Date: 2015-01-29
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### Typedefs          ####
typedef struct q{
			int number;
			struct q *next;
			struct q *prev;
} REGTYPE;

/*
/ Randomizes 5 numbers to 5 different REGTYPES,
/ creates a linked list where the types know the 
/ previous and the next element in the list.
*/
REGTYPE* random_list();

/*
/ Adds another element at the beginning of the linked list.
/ In: Linked list REGTYPE, integer to be inserted
/ Out: REGTYPE pointer.
*/
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
	int nr = 0;
	REGTYPE *akt_post, *head=NULL;

	srand(time(0)); // random seed
	head=random_list();
	akt_post=head;
	while(akt_post!=NULL)
	{
		printf("Post nr %d : %d\n", nr++, akt_post->number);
		akt_post=akt_post->next;
	}
	printf("Adding 1 to head\n");
	head=add_first(head, 1);
	akt_post=head;
	nr=0;
	while(akt_post!=NULL)
	{
		printf("Post nr %d : %d\n", nr++, akt_post->number);
		akt_post=akt_post->next;
	}

	//Free allocated memory
	while((akt_post=head)!=NULL)
	{
		head=akt_post->next;
		free(akt_post);
	}
	return 0;

}
// ====     Slut main   ======================================
REGTYPE* random_list(){
	int i=0;
	REGTYPE *top, *old, *item;
	top = (REGTYPE*) malloc(sizeof(REGTYPE));
	top->number = random() % 100;
	item = top;
	while(i < MAX)
	{
			old = item;
			item = (REGTYPE*) malloc(sizeof(REGTYPE));
			item->number = random() % 100;
			old->next = item;
			item->prev = old;
			++i;
	}
	return(top);
}
//==========================================================                 
REGTYPE* add_first(REGTYPE* temp, int data)
{
	REGTYPE *first;
	first = (REGTYPE*) malloc(sizeof(REGTYPE));
	first->number = data;
	first->next = temp;
	temp->prev = first;

	return(first);
}