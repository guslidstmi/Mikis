#include <stdio.h>

#define PORTROW 0x09C0
#define PORTCOL 0x09C1
#define REG8(x) *((unsigned char *)(x))

int main(void) {
	
	unsigned char row, col;
	puts("I am alive!");

	while(1)
	{
		int i, j;
		row = REG8(PORTROW);
		col = REG8(PORTCOL);
		for(i = 0; i < 4; i++)
		{
			row = row & i;
			
			for(j = 0; j < 4; j++)
			{
				col = col & 1;
				printf("%x\n", col);
				
				if(!(col & 3))
				{
					puts("yey it works!");
				}
				col >> 1;
			}
			row >> 1;
		}
			
	}
	
return 0;

}