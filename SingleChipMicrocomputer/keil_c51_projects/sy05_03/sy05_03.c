#include <reg51.h>

#define uchar unsigned char
#define uint unsigned int

// 
uchar code seg_code[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

uchar hour = 16;
uchar minute = 10;
uchar second = 10;

void delay(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 110; y > 0; y--);
}

void display()
{
    uchar i;
    for (i = 0; i < 8; i++)
    {
        switch (i)
        {
            case 0:
                P2 = 0x01;
                P0 = seg_code[hour / 10];
                break;
            case 1:
                P2 = 0x02;
                P0 = seg_code[hour % 10];
                break;
            case 2:
                P2 = 0x04;
                P0 = 0xbf; 
                break;
            case 3:
                P2 = 0x08;
                P0 = seg_code[minute / 10];
                break;
            case 4:
                P2 = 0x10;
                P0 = seg_code[minute % 10];
                break;
           	case 5:
                P2 = 0x20;
                P0 = 0xbf; 
                break;
            case 6:
                P2 = 0x40;
                P0 = seg_code[second / 10];
                break;
            case 7:
                P2 = 0x80;
                P0 = seg_code[second % 10];
                break;
        }
        delay(1);
    }
}

void timer0_init()
{
    TMOD = 0x01;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void timer0() interrupt 1
{
    static uchar count = 0;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
	EA=1; 
	ET0=1; 
	TR0=1; 


    count++;
    if (count == 20)
    {
        count = 0;
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
            if (minute == 60)
            {
                minute = 0;
                hour++;
                if (hour == 24)
                {
                    hour = 0;
                }
            }
        }
    }
}

void main()
{
    timer0_init();
    while (1)
    {
        display();
    }
}