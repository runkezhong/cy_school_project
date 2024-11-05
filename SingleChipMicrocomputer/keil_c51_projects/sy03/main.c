// 4.5 LED数码管显示
#include <reg51.h>
//统计K5键按下次数，并数码管动态实时显示。
#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint  unsigned int
//0~9的共阳数码管段码表
uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
sbit K5=P1^5;
sbit wexu=P3^0;
sbit duxu=P3^1;
void delayms(uint y){
	uint i,j;
	for(i=y;i>0;i--)
		for(j=110;j>0;j--)
			;
}
void display(uchar shu)
{
	uchar wk=0x04;
	uchar i;
	uchar buf[2];
	buf[0]=ledmod[shu/10];
	buf[1]=ledmod[shu%10];
	for (i=0;i<2;i++)
	{
		wexu=1;
		P2=wk;
		duxu=1;
		P0=buf[i];
		wk=_crol_(wk,1);
		delayms(10);
		P0=0xff;
	}
}

void main()
{
 	char num;
	num=0;
	while(1)
	{
	 	display(num);
		if(K5==0)
		{
		 	delayms(10);
			if(K5==0)
			{
			 	num++;
				if(num==100)
				{
					num=0;
				}
			}
		}
		while(!K5); // 等待释放
	}
}