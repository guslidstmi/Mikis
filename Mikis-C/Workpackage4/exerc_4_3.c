#define PORTIN 0x0400
#define PORTOUT 0x0402
#define REG8(x) *((unsigned char *)(x))

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
