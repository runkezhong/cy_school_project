#include <reg51.h>

sbit D1=P2^0;

int0_srv() interrupt 0
{
 	D1=!D1;
}
main()
{
	/*

	  �жϳ�ʼ����Ҳ���Էֿ�д����,EA=1��EX0=1;
	*/
	IE=0x81;
	IT0=1;
	while(1);
}