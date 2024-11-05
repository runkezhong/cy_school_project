#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int



//0~9 �Ĺ�������ܶ����
uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xFF,0x00}; // 0-9

sbit K0=P1^0;
sbit K1=P1^1;
sbit K2=P1^2;
sbit K3=P1^3;
sbit K4=P1^4;
sbit K5=P1^5;	  // ������ P1.5 ���ŵİ�����������ⰴ�����롣
sbit K6=P1^6;	  // ������ P1.6 ���ŵİ�����������ⰴ�����롣
sbit K7=P1^7;	  // ������ P1.5 ���ŵİ�����������ⰴ�����롣



sbit wexu=P3^0;
sbit duxu=P3^1;
void delayms(uint y)
{
	uint i,j;
	for(i=y;i>0;i--)
	for(j=110;j>0;j--)
	;
}

void display(uint shu, uint btn)
{
	uchar wk=0x01; //�ñ������ڴ�λѡ���ݣ�0000 0100��
	uchar i; //�ı�λѡ��ѭ������
	uchar buf[4]; //����һ�����黺��Ҫ��ʾ�� shu

	/*
	if (shu >= 0 ){
		 // �ֽ��ǧλ����λ��ʮλ�͸�λ
	    buf[0] = ledmod[shu / 1000]; // ǧλ
	    buf[1] = ledmod[(shu % 1000) / 100]; // ��λ
	    buf[2] = ledmod[(shu % 100) / 10]; // ʮλ
	    buf[3] = ledmod[shu % 10]; // ��λ
	}
	 */

	switch(btn){
		case -1:
			buf[0] = buf[1] = buf[2] = buf[3] = ledmod[10];
			break; 
		case -2:
			buf[0] = buf[1] = buf[2] = buf[3] = ledmod[11];
			break;
		case -3:
			buf[0] = ledmod[10];
			buf[1] = ledmod[10]; // ��λ
		    buf[2] = ledmod[10]; // ʮλ
		   	buf[3] = ledmod[shu % 10]; // ��λ
			break;
		case -4:
			buf[0] = ledmod[10];
			buf[1] = ledmod[10]; // ��λ
		    buf[2] = ledmod[(shu % 100) / 10]; // ʮλ
		   	buf[3] = ledmod[shu % 10]; // ��λ
			break;
		case -5:
			buf[0] = ledmod[10];
			buf[1] = ledmod[(shu % 1000) / 100]; // ��λ
		    buf[2] = ledmod[(shu % 100) / 10]; // ʮλ
		   	buf[3] = ledmod[shu % 10]; // ��λ
			break;
		 
		default:
			 // �ֽ��ǧλ����λ��ʮλ�͸�λ
		   	buf[0] = ledmod[shu / 1000]; // ǧλ
			buf[1] = ledmod[(shu % 1000) / 100]; // ��λ
		    buf[2] = ledmod[(shu % 100) / 10]; // ʮλ
		   	buf[3] = ledmod[shu % 10]; // ��λ
			
	}


	for(i=0;i<4;i++)
	{
		wexu = 1; // ��λѡ������ U3
        P2 = wk; // λѡ��ѡ��ǰҪ��ʾ�������
        wexu = 0; // �ر�λѡ������

		duxu = 1; // �򿪶�ѡ������ U2
        P0 = buf[i]; // �����뷢�͸������
        duxu = 0; // �رն�ѡ������

		wk = _crol_(wk, 1); // ѭ����λ��ѡ����һ�������
        delayms(10); // ������ʱ�������ȶ���ʾ
        P0 = 0xff; // ������������Ӱ����
	}
	
	

}
void main(){

	uint frist_P3 = -1 ,frist_P4 = -1 , frist_P5 = -1;
	uint btn = 0;
	// char num;
	uint num;  // ��Ϊ unsigned int��֧�ָ������ֵ��Χ
	num = 0;
	while(1)
	{
		display(num,btn); // ��ʾ��ǰ��ֵ

		if (K0 == 0){
			delayms(10); // ��������
            if(K0 == 0) // ȷ�ϰ�������
            {

            	btn = -1;
            } 	

		}
		while(!K0);


		if (K1 == 0){
			delayms(10); // ��������
            if(K1 == 0) // ȷ�ϰ�������
            {

            	btn = -2;

            } 	

		}
		while(!K1);


		if (K2 == 0){
			delayms(10); // ��������
            if(K2 == 0) // ȷ�ϰ�������
            {
				
				btn = -3;
				num++;	
				if(num > 9) // ��ֵ��9999������Ϊ0
                {
                    num = num % 10;
                }	
            } 	

		}
		while(!K2);

		if (K3 == 0){
			delayms(10); // ��������
            if(K3 == 0) // ȷ�ϰ�������
            {

            	btn = -4;
				num++;	
				if(num > 99) // ��ֵ��9999������Ϊ0
                {
                    num = num % 100;
                }
            } 	

		}
		while(!K3);

		if (K4 == 0){
			delayms(10); // ��������
            if(K4 == 0) // ȷ�ϰ�������
            {

            	btn = -5;
				num++;	
				if(num > 999) // ��ֵ��9999������Ϊ0
                {
                    num = num % 1000;
                }
            } 	

		}
		while(!K4);




	
        if(K5 == 0) // ��ⰴ���Ƿ���
        {
            delayms(10); // ��������
            if(K5 == 0) // ȷ�ϰ�������
            {
				btn = 0;
            	num = 0;
            }
        }
        while(!K5); // �ȴ������ͷ�
		

		if(K6 == 0)	{
		 	delayms(10);
			if (K6 == 0){
				btn = 0;
			 	num++;
				if(num > 9999) // ��ֵ��9999������Ϊ0
                {
                    num = 0;
                }
			}
		}
		while(!K6); // �ȴ������ͷ�

		if(K7 == 0)	{
		 	delayms(10);
			if (K7 == 0){
			 	btn = 0;
				if (num <= 0){
					num = 0;
					break;
				}
				num--;
			}
		}
		while(!K7); // �ȴ������ͷ�


	}
}