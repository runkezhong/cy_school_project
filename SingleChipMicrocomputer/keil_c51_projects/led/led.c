#include<reg52.h>		 
sbit LED=P2^0;			//将端口P2^0定义为LED
void main ()			//主函数
{
	LED=0;			    //LED端口为低电平
}
