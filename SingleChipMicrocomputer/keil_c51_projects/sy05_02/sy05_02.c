
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wexu = P3^0;
sbit duxu = P3^1;

// ��ʱ������
uchar time=0;
// �������
uchar shu=0;
// ʮλ����
uchar shi;
// ��λ����
uchar ge;

// �������ֵ
uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

// ��ʱ����
void delayms(uint y)
{
 	uint i, j;
	for(i=y;i>0;i--)
		for(j=110;j>0;j--)
			;
}

// ��ʾ
display(uchar shu)
{
	shi=shu/10;
	ge=shu%10;

	wexu=1;	 // λѡ��
	P2=0x04;	// ʮλ�����
	duxu=1;
	P0=ledmod[shi];
	delayms(5);
	P0=0xff;   // �ر���ʾ

	wexu=1;		   //λѡ��
	P2=0x08;
	duxu=1;
	P0=ledmod[ge];
	delayms(5);
	P0=0xff;   // �ر���ʾ
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
		// ��ʾ��ǰ����
	 	display(shu);
		// �����������P1�˿�
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