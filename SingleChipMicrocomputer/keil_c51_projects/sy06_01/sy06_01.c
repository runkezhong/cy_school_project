#include <reg51.h>

unsigned char code Tab[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F,0xaa,0x0f,0xf0,0x55};
void Send(unsigned char dat)
{
 	SBUF=dat;
	while(TI==0)
		;
	TI=0;
}
void delay(void)
{

   unsigned int m;
   for(m=0;m<50000;m++)
   	;
}

void main(void)
{
 	unsigned char i;
	TMOD=0x20;
	SCON=0x40;
	PCON=0x00;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	while(1)
	{
	 	for(i=0;i<12;i++)
		{
			Send(Tab[i]);
			delay();
		}
	}
}
