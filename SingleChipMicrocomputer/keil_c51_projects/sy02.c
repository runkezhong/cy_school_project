#include <reg51.h>
#define uchar unsigned char // 宏定义
#define uint unsigned int
sbit D0 =P2^0;
sbit K0 =P1^0;
sbit D1 =P2^1;
sbit K1 = P1^1;
void delayms(uint y)
{
    uint i, j;
    for (i = y; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}
main(void)
{
	D0 = 1;
	D1 = 1;
    while (1)
    {
        if (K0 == 0)
        {
            // D0 初始是灭的
            // 判断按键是否被按下
            delayms(10);
            if (K0 == 0)
            {
				D0 = !D0;								 
            }
            while (!K0);
        }
		if (K1 == 0)
		{
		 	delayms(10);
			if (K1 == 0)
			{
			 	D1 = !D1;
			}
			while (!K1);
		}
    }
}