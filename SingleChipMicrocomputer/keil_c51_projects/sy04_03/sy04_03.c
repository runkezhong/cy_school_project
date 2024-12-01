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
sbit K1 = P3^3;
uchar code DSY_CODE[] =
{
 	0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,
	0x88,0x83,0xC6,0xA1,0x86,0x8E,0x89
};
// sbit K1 = P1^1;
void delayms(uint y)
{
    uint i, j;
    for (i = y; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}
int i;
void main()
{
	
	//D0 = 1;
	//D1 = 1;
	uchar k0Pressed = 0, k1Pressed = 0;
	uchar j;
	P0 = 0x00; //  ˝¬Îπ‹¡¡∆¡
	P1 = 1;
    while (1)
    {
		
		P2 = 0xAA;
		delayms(800);		
		P2 = 0x55;
		delayms(800);
		if (K1 == 0 && k1Pressed == 0)
		{
			delayms(20);
			if (K1 == 0)
			{
				k1Pressed = 1;
				
				for (j=0;j<16;j++)
				{
				 	P0=DSY_CODE[j];
					delayms(500);
				}
				P0 = 0xFF; //  ˝¬Îπ‹∫⁄∆¡
			   	// while (!K1);
			}
	
		} else if (K1 == 1){
		 	k1Pressed = 0; // ÷ÿ÷√K1◊¥Ã¨
		}
		if (K0 == 0 && k0Pressed == 0)
		{
			delayms(20);
			if (K0 == 0)
			{
			 	k0Pressed = 1;
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
			}			
		} else if (K0 == 1) {
		 	k0Pressed = 0;
		}

    }
}