#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int

//0~9 的共阳数码管段码表
uchar code ledmod[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,
						0x90,0x88,0x83,0xa7,0xa1,0x86,0x8e,0xff}; // 0-9
/*
sbit K0=P1^0;
sbit K1=P1^1;
sbit K2=P1^2;
sbit K3=P1^3;
sbit K4=P1^4;
sbit K5=P1^5;	  // 连接在 P1.5 引脚的按键，用来检测按键输入。
sbit K6=P1^6;	  // 连接在 P1.6 引脚的按键，用来检测按键输入。
sbit K7=P1^7;	  // 连接在 P1.5 引脚的按键，用来检测按键输入。
*/


sbit wexu=P3^0;
sbit duxu=P3^1;

uchar key;
void delayms(uint y)
{
	uint i,j;
	for(i=y;i>0;i--)
	for(j=110;j>0;j--)
	;
}

void display(uchar num)
{
	/*
	uchar wk=0x01; //该变量用于存位选数据（0000 0100）
	uchar i; //改变位选的循环变量
	uchar buf[4]; //定义一个数组缓存要显示的 shu
	*/
	/*
	if (shu >= 0 ){
		 // 分解出千位、百位、十位和个位
	    buf[0] = ledmod[shu / 1000]; // 千位
	    buf[1] = ledmod[(shu % 1000) / 100]; // 百位
	    buf[2] = ledmod[(shu % 100) / 10]; // 十位
	    buf[3] = ledmod[shu % 10]; // 个位
	}
	 */
	/*
	switch(btn){
		case -1:
			buf[0] = buf[1] = buf[2] = buf[3] = ledmod[10];
			break; 
		case -2:
			buf[0] = buf[1] = buf[2] = buf[3] = ledmod[11];
			break;
		case -3:
			buf[0] = ledmod[10];
			buf[1] = ledmod[10]; // 百位
		    buf[2] = ledmod[10]; // 十位
		   	buf[3] = ledmod[shu % 10]; // 个位
			break;
		case -4:
			buf[0] = ledmod[10];
			buf[1] = ledmod[10]; // 百位
		    buf[2] = ledmod[(shu % 100) / 10]; // 十位
		   	buf[3] = ledmod[shu % 10]; // 个位
			break;
		case -5:
			buf[0] = ledmod[10];
			buf[1] = ledmod[(shu % 1000) / 100]; // 百位
		    buf[2] = ledmod[(shu % 100) / 10]; // 十位
		   	buf[3] = ledmod[shu % 10]; // 个位
			break;
		 
		default:
			 // 分解出千位、百位、十位和个位
		   	buf[0] = ledmod[shu / 1000]; // 千位
			buf[1] = ledmod[(shu % 1000) / 100]; // 百位
		    buf[2] = ledmod[(shu % 100) / 10]; // 十位
		   	buf[3] = ledmod[shu % 10]; // 个位
			
	}


	for(i=0;i<4;i++)
	{
		wexu = 1; // 打开位选锁存器 U3
        P2 = wk; // 位选，选择当前要显示的数码管
        wexu = 0; // 关闭位选锁存器

		duxu = 1; // 打开段选锁存器 U2
        P0 = buf[i]; // 将段码发送给数码管
        duxu = 0; // 关闭段选锁存器

		wk = _crol_(wk, 1); // 循环移位，选择下一个数码管
        delayms(10); // 短暂延时，用于稳定显示
        P0 = 0xff; // 消隐，避免重影现象
	}
	*/
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
	P1=0xf0;
	if((P1&0xf0)!=0xf0)
	{
	 	delayms(10);
		if((P1&0xf0)!=0xf0)
		{
		 	P1=0xfe;
			temp=P1;
			temp=temp&0xf0;
			if (temp!=0xf0)
			{
				delayms(10);
				temp=P1;
				temp=temp&0xf0;
				if(temp!=0xf0)
				{
					temp=P1;
					switch(temp)
					{
					 	case 0xee: key=0;
							break;
						case 0xde: key=1;
							break;
						case 0xbe: key=2;
							break;
						case 0x7e: key=3;
							break;
					}
					while(temp!=0xf0)
					{
						temp=P1;
						temp=temp&0xf0;
					}
				}
			}

			P1=0xfd;
			temp=P1;
			temp=temp&0xf0;
			if(temp!=0xf0)
			{
			 	delayms(10);
				temp=P1;
				temp=temp&0xf0;
				if(temp!=0xf0)
				{
				 	temp=P1;
					switch(temp)
					{
					 	case 0xed: key=4;
							break;
						case 0xdd: key=5;
							break;
						case 0xbd: key=6;
							break;
						case 0x7d: key=7;
							break;
					}
					while(temp!=0xf0)
					{
					 	temp=P1;
						temp=temp&0xf0;
					}
				}
			}

			P1=0xfb;
			temp=P1;
			temp=temp&0xf0;
			if(temp!=0xf0)
			{
			 	delayms(10);
				temp=P1;
				temp=temp&0xf0;
				if(temp!=0xf0)
				{
				 	temp=P1;
					switch(temp)
					{
					 	case 0xeb: key=8;
							break;
						case 0xdb: key=9;
							break;
						case 0xbb: key=10;
							break;
						case 0x7b: key=11;
							break;
					}
					while(temp!=0xf0)
					{
					 	temp=P1;
						temp=temp&0xf0;
					}
				}
			}
			P1=0xf7;
			temp=P1;
			temp=temp&0xf0;
			if(temp!=0xf0)
			{
			 	delayms(10);
				temp=P1;
				temp=temp&0xf0;
				if(temp!=0xf0)
				{
				 	temp=P1;
					switch(temp)
					{
					 	case 0xe7: key=12;
							break;
						case 0xd7: key=13;
							break;
						case 0xb7: key=14;
							break;
						case 0x77: key=15;
							break;
					}
					while(temp!=0xf0)
					{
					 	temp=P1;
						temp=temp&0xf0;
					}
				}
			}
		}
	}
	return (key);
}
void main(){
	while(1)
	{
	 	juzhen_keyscan();
		display(key);
	}
  	/*
	uint frist_P3 = -1 ,frist_P4 = -1 , frist_P5 = -1;
	uint btn = 0;
	// char num;
	uint num;  // 改为 unsigned int，支持更大的数值范围
	num = 0;
	while(1)
	{
		display(num,btn); // 显示当前数值

		if (K0 == 0){
			delayms(10); // 防抖处理
            if(K0 == 0) // 确认按键按下
            {

            	btn = -1;
            } 	

		}
		while(!K0);


		if (K1 == 0){
			delayms(10); // 防抖处理
            if(K1 == 0) // 确认按键按下
            {

            	btn = -2;

            } 	

		}
		while(!K1);


		if (K2 == 0){
			delayms(10); // 防抖处理
            if(K2 == 0) // 确认按键按下
            {
				
				btn = -3;
				num++;	
				if(num > 9) // 数值到9999后重置为0
                {
                    num = num % 10;
                }	
            } 	

		}
		while(!K2);

		if (K3 == 0){
			delayms(10); // 防抖处理
            if(K3 == 0) // 确认按键按下
            {

            	btn = -4;
				num++;	
				if(num > 99) // 数值到9999后重置为0
                {
                    num = num % 100;
                }
            } 	

		}
		while(!K3);

		if (K4 == 0){
			delayms(10); // 防抖处理
            if(K4 == 0) // 确认按键按下
            {

            	btn = -5;
				num++;	
				if(num > 999) // 数值到9999后重置为0
                {
                    num = num % 1000;
                }
            } 	

		}
		while(!K4);




	
        if(K5 == 0) // 检测按键是否按下
        {
            delayms(10); // 防抖处理
            if(K5 == 0) // 确认按键按下
            {
				btn = 0;
            	num = 0;
            }
        }
        while(!K5); // 等待按键释放
		

		if(K6 == 0)	{
		 	delayms(10);
			if (K6 == 0){
				btn = 0;
			 	num++;
				if(num > 9999) // 数值到9999后重置为0
                {
                    num = 0;
                }
			}
		}
		while(!K6); // 等待按键释放

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
		while(!K7); // 等待按键释放


	}
	*/
}