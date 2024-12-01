#include <reg51.h>

unsigned char a;
unsigned char code seg[] = {0xc0, 0xF9, 0xA4,0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

int main()

{
 	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	SCON=0x50;
	EA=1;
	ES=1;
	TR1=1;
	while(1)
	{

	}

}

void serial() interrupt 4
{
 	if (RI)
	{
	 	RI=0;
		a=SBUF;
		P0=seg[a];
	}

}