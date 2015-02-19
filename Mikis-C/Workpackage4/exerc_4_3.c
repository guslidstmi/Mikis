/*===================================
File name: exerc_4_3.c
Date: 2015-02-15
Group Number: 8
Member that contributed:
Johan Nilsson
Mikeala Lidström
Henrik Edholm
Demonstration code: 
===================================*/

#define PORTIN 0x0400
#define PORTOUT 0x0402
#define REG8(x) *((unsigned char *)(x))

/*
* while 7th bit in "in" is set to 1,
* set bit 0 in "out" to 1, iterate through each bit in "out".
* when bit 7 in out is 1, switch back to bit 0, repeat
* IN: void. OUT: 0
*/
int main(void)
{

	unsigned char in, out;	
	in = REG8(PORTIN);
	out = 1;
	while(in & 0x80)
	{
		int i;
		REG8(PORTOUT) = out;
		if(out & 0x80)
			out = 1;
		else
			out = out << 1;
		in = REG8(PORTIN);
		for(i = 0; i < 100; i++)
			;
	}
	return 0;
}
