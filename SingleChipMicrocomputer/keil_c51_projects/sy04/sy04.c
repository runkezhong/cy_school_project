#include <reg51.h>

sbit D1=P2^0;

int0_srv() interrupt 0
{
 	D1=!D1;
}
main()
{
	/*

	  中断初始化，也可以分开写两句,EA=1和EX0=1;
	*/
	IE=0x81;
	IT0=1;
	while(1);
}