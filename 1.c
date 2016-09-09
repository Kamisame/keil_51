#include<reg51.h>
sbit dula = P0^6;
sbit wela = P0^7;
void main()
{
 wela=1;
 P1=0xFE;
 wela=0;

 dula=1;
 P1=0x7F;
 dula=0;
 while(1);
 }
