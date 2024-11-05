#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char // ????
#define uint unsigned int
sbit D0 = P2^0;
sbit D1 = P2^1;
sbit D2 = P2^2;
sbit D3 = P2^3;
sbit D4 = P2^4;
sbit D5 = P2^5;
sbit D6 = P2^6;
sbit D7 = P2^7;

sbit K0 = P3^2;
// sbit K1 = P1^1;
void delayms(uint y)
{
    uint i, j;
    for (i = y; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}
int i;
uchar d=0;
void main()
{
	D0 = 1;
	D1 = 1;
    while (1)
    {
		
		P2 = 0xAA;
		delayms(800);		
		P2 = 0x55;
		delayms(800);
		if (K0 == 0)
		{
			P2 = 0xFF;
			for(i=0; i<8; i++)
			{
			 	switch(i)
				{
				 	case 0: D0 = 0; break;
					case 1: D1 = 0; break;
					case 2: D2 = 0; break;
					case 3: D3 = 0; break;
					case 4: D4 = 0; break;
					case 5: D5 = 0; break;
					case 6: D6 = 0; break;
					case 7: D7 = 0; break;
				}
				delayms(500);
				P2 = 0xFF;
			}
			for(i=8; i>0; --i)
			{
			 	switch(i)
				{
				 	case 0: D0 = 0; break;
					case 1: D1 = 0; break;
					case 2: D2 = 0; break;
					case 3: D3 = 0; break;
					case 4: D4 = 0; break;
					case 5: D5 = 0; break;
					case 6: D6 = 0; break;
					case 7: D7 = 0; break;
				}
				delayms(500);
				P2 = 0xFF;
			}
			while (!K0);			
		}

    }
}