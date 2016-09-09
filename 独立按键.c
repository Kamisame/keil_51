#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit key1=P1^4;
sbit key2=P1^5;
sbit key3=P1^6;
sbit key4=P1^7;

uchar code table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,
0x7d,0x07,0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

void delayms(uint);
uchar numt0,num;
void display(uchar numdis)
{
  uchar shi,ge;
  shi=numdis/10;
  ge=numdis%10;

 
  P0=table[shi]; 
  P2=0xfd;
  delayms(5);
  
  P0=table[ge]; 
  P2=0xfe;
  delayms(5);
}

void delayms(uint xms)
{
  uint i,j;
  for(i=xms;i>0;i--)
  for(j=110;j>0;j--);
}

void init()
{
    TMOD=0x01;
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
    EA=1;
	ET0=1;
}
    
void keyscan()
{
  if(key1==0)
  {
    delayms(10);
	if(key1==0)
	 {
	   num++;
	   if(num==60)
	         num=0;
		 while(!key1);
	  }
   }
   if(key2==0)
   {
     delayms(10);
	 if(key2==0)
	 {
	   if(num==0)
	     num=60;
		 num--;
		 while(!key2);
	  }
   }
  if(key3==0)
  {
    delayms(10);
	if(key3==0)
	{
	  num=0;
	  while(!key3);
	}
  }
  if(key4==0)
  {
   delayms(10);
   if(key4==0)
    {
	  while(!key4);
	  TR0=~TR0;
    }
  }
}

void main()
{
  init();
  while(1)
  {
    keyscan(); 
	display(num);
  }
}

void T0_time() interrupt 1
{

   TH0=(65536-45872)/256;
   TL0=(65536-45872)%256;
   numt0++;
  if(numt0==20)
   {
     numt0=0;
	 num++;
	 if(num==60)
	     num=0;
   }
}

