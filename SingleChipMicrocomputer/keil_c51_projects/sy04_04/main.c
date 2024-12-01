#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int uint16;

sbit k7 = P1^7;
sbit sp = P3^0;
unsigned int a = 0;

delay(unsigned int i)
{
 	while(i--);
}

void Timer0() interrupt 1
{
 	sp=!sp;
	a++;
	if(a<500)
	{
		TH0=(65536-700)/256;
		TL0=(65536-700)%256;	
	} else if (a<1200)
	{
	 	TH0=(65536-1000)/256;
		TL0=(65536-1000)%256;
	} else {
	 	TR0=0;
		a=0;
	}
}

void main()
{
	sp=0;
	IE=0x82;
	TMOD=0x01;
	TH0=(65536-700)/256;
	TL0=(65536-700)%256;
	while(1)
	{
	 	k7=1;
		if(k7==0)
		{
		 	delay(1000);
			if(k7==0)
			{
			 	TR0=1;
				while(k7==0);
			}
		}
	}
}