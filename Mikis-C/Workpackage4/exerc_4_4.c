/*===================================
File name: exerc_4_4.c
Date: 2015-02-15
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#include <stdio.h>

#define PORT 0x09C0
#define REG8(x) *((unsigned char *)(x))

/*
* Get portinformation to row.
* if row is low, calculate which button is pressed.
* IN: void. OUT: 0
*/
int main(void)
{
	while(1)
	{
		unsigned char row;

		row = REG8(PORT);
		if(!(row & 0x80))
		{
			if(row > 0x09)
				putchar(row + 55);
			else
				putchar(row + '0');
				
		}
	}	
	return 0;
}
