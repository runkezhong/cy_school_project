#include <reg51.h>
#define uchar unsigned char // �궨��
#define uint unsigned int
sbit D0 =P2^0;
sbit K0 =P1^0;
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
    while (1)
    {
        if (K0 == 0)
        {
            // D0 ��ʼ�����
            // �жϰ����Ƿ񱻰���
            delayms(10);
            if (K0 == 0)
            {
				D0 = !D0;
            }
            while (!K0);
        }
    }
}