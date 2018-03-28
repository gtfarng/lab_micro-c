#include<avr/io.h>
int main(void)
{
    unsigned char TB7SEG[] = {  0b00111111,0b00000110,0b01011011,0b01001111,
			       				0b01100110,0b01101101,0b01111101,0b00000111,
			       				0b01111111,0b01101111,0b01110111,0b01111100,
			       				0b00111001,0b01011110,0b01111001,0b01110001 };				
    unsigned char INP = 0x00;
    unsigned char COUNT = 0x00;		
		  DDRC = 0xFF; 
		  DDRD = 0x00; 
		  PORTC = TB7SEG[0];
	    int tmp = 0;
	    while (1) 
	  {	INP = PIND;
		INP &= 0x04;
		if(!INP)
		   tmp=1;
		if(tmp)
		{  INP = PIND;
		   INP &= 0x04;
			if(INP)
			{  if(COUNT == 15)
			      COUNT = 0;
			   else
			      COUNT += 1;
			      tmp = 0;
			}
		}
		PORTC = TB7SEG[COUNT];
    }
}
