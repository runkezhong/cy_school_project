#include <reg51.h>

sbit key=P3^7;
unsigned char a;

delay()
{
 	unsigned int i;
	for(i=0;i<200;i++);
}


sendB(unsigned char da)
{
	SBUF=da;
	while(!TI);
	TI=0;
}

int main()
{
	// 定时器T1方式2作波特率发生器
 	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	SCON=0x40;
	TR1=1;
	while(1)
	{
	 	if (key==0)
		{
		 	delay();
			if (key==0)
			{
			 	sendB(a);
				a=(a+1)%10;
				while(key==0)
				{
					delay();
				}
			}
		}
	}

}