#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int

sbit wexu=P3^0;
sbit duxu=P3^1;

uchar key;	// 存储按键值

uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,
						0x90,0x88,0x83,0xa7,0xa1,0x86,0x8e,0xff};

void delayms(uint y)
{
 	uint i,j;
	for(i=y;i>0;i--)
		for(j=110;j>0;j--)
			;
}

void display(uchar num)
{
 	wexu=1;
	P2=0x0f;
	duxu=1;
	P0=ledmod[num];
	delayms(10);
	P0=0xff;
}

uchar juzhen_keyscan()
{
 	uchar temp;
	// P1.0~P1.3行线输出都为0，P1.4~P1.7列线都为1，准备读列状态
	P1=0xf0;
	if((P1&0xf0)!=0xf0)
	{

	}

}