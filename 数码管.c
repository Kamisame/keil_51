#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int 

uchar num;
uchar a;
uchar code table[]=
{
0x3f,0x06,0x5b,0x4f,0x66,0x6d,
0x7d,0x07,0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

void delayms(uint);
void main()
{
  a=0xfe;
  while(1)
  {
  for(num=1;num<9;num++)
  {
  P1=a;
  a=_crol_(a, 1);
  P0=table[num];
  if(num==8||num==1)
  delayms(1000);
  else delayms(1000);
  }
  for(num=8;num>0;num--)
  {
  a=_cror_(a, 1);
  P1=a;
  P0=table[num];
  if(num==8||num==1)
  delayms(1000);
  else delayms(1000);
  }
 }
 }
 void delayms(uint xms)
 {
  uint i,j;
  for(i=xms;i>0;i--)
  for(j=110;j>0;j--);
  }
