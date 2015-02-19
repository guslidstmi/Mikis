/*===================================
File name: exerc_4_5.c
Date: 2015-02-15
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#include <stdio.h>

#define PORTROW 0x09C0
#define PORTCOL 0x09C1
#define REG8(x) *((unsigned char *)(x))

/*
* Set each row to low.
* iterate through column to check if one of them is low
* if column is low, print out the key with the 
* help of row and col number.
* IN: void. OUT: 0
*/
int main(void) {
	
	puts("I am alive!");

	while(1)
	{
		int i, j;
		
		for(i = 0; i < 4; i++)
		{
			REG8(PORTROW) = 0x01 << i;
			for(j = 0; j < 4; j++)
			{
				if(!(REG8(PORTCOL) & 0x01 << j))
				{

					switch(i){
						case 0 :
							switch(j)
							{
								case 0 :
									putchar('C');
									break;
								case 1 :
									putchar('8');
									break;
								case 2 :
									putchar('4');
									break;
								case 3 :
									putchar('0');
									break;
							}
							break;
						case 1 :
							switch(j)
							{
								case 0 :
									putchar('D');
									break;
								case 1 :
									putchar('9');
									break;
								case 2 :
									putchar('5');
									break;
								case 3 :
									putchar('1');
									break;
							}
							break;
						case 2 :
							switch(j)
							{
								case 0 :
									putchar('E');
									break;
								case 1 :
									putchar('A');
									break;
								case 2 :
									putchar('6');
									break;
								case 3 :
									putchar('2');
									break;
							}
							break;
						case 3 :
							switch(j)
							{
								case 0 :
									putchar('F');
									break;
								case 1 :
									putchar('B');
									break;
								case 2 :
									putchar('7');
									break;
								case 3 :
									putchar('0');
									break;
							}
							break;
					}
				}
				
			}
			
		}
		for(i = 0; i < 50; i++)
			;

	}
	
return 0;

}