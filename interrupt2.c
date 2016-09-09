#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit led=P2^5;

uchar code table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,
0x7d,0x07,0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void delayms(uint);
void display(uchar,uchar,uchar,uchar,uchar,uchar);
uchar num,num1,num2,num3,num4,m,s,h1,h2,h3,h4;
void main()
{
 TMOD =0x11;
 TH0=(65536-45872)/256;
 TL0=(65536-45872)%256;
 TH1=(65536-45872)/256;
 TL1=(65536-45872)%256;
 EA=1;
 ET0=1;
 ET1=1;
 TR0=1;
 TR1=1;

 while(1)
    display(m,s,h1,h2,h3,h4);
}

void display(uchar m,uchar s,uchar h1,uchar h2,uchar h3,uchar h4)
{

  P1=0xbf;
  P0=table[m];
  delayms(3);
  
  P1=0x7f;
  P0=table[s]
  delayms(3);


  P1=0xdf;
  P0=0x40;
  delayms(3);

  P1=0xf7;
  P0=table[h1];
  delayms(3);
  
  P1=0xef;
  P0=table[h2];
  delayms(3);

  P1=0xfb;
  P0=0x40;
  delayms(3);

  P1=0xfd;
  P0=table[h3];
  delayms(3);
  
  P1=0xfe;
  P0=table[h4];
  delayms(3); 
}

void delayms(uint xms)
{
 uint i,j;
 for(i=xms;i>0;i--)
 for(j=110;j>0;j--);
}

void T0_time() interrupt 1
{
  TH0=(65536-45872)/256;
  TL0=(65536-45872)%256;
  num1++;
  if(num1==10)
  {
    num1=0;
	led=~led;
  }
}

void T1_time() interrupt 3
{
  TH1=(65536-45872)/256;
  TL1=(65536-45872)%256;
  num2++;
  if(num2==20)
  {
    num2=0;
	num++;

	if(num==60)
       {
        num=0;
        num3++;
      }
    if(num3==60)
     {
	   num3=0;
	   num4++;
	 }
	 if(num4==24)
	 num4=0;

   m=(num/10)%10;
   s=num%10;
   h1=(num3/10)%10;
   h2=num3%10;
   h4=(num4/10)%10;
   h3=num4%10;
  }
}
