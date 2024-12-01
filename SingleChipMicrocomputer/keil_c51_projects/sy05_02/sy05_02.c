
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wexu = P3^0;
sbit duxu = P3^1;

// 计时器变量
uchar time=0;
// 输出数字
uchar shu=0;
// 十位数字
uchar shi;
// 个位数字
uchar ge;

// 数码管码值
uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

// 延时函数
void delayms(uint y)
{
 	uint i, j;
	for(i=y;i>0;i--)
		for(j=110;j>0;j--)
			;
}

// 显示
display(uchar shu)
{
	shi=shu/10;
	ge=shu%10;

	wexu=1;	 // 位选择
	P2=0x04;	// 十位数码管
	duxu=1;
	P0=ledmod[shi];
	delayms(5);
	P0=0xff;   // 关闭显示

	wexu=1;		   //位选择
	P2=0x08;
	duxu=1;
	P0=ledmod[ge];
	delayms(5);
	P0=0xff;   // 关闭显示
}

main(void)
{
	// 
 	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	while(1)
	{
		// 显示当前数字
	 	display(shu);
		// 将数字输出到P1端口
		P1=shu;
	}
}

void time0() interrupt 1 using 1
{
 	TR0=0;
	time++;
	if(time==20)
	{
	 	time=0;
		shu++;
		if(shu==100)
		shu=0;
	}
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TR0=1;
}