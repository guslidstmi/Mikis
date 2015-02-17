#include <stdio.h>

#define PORT 0x09C0
#define REG8(x) *((unsigned char *)(x))

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
