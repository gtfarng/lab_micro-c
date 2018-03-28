#include <avr/io.h>
int main()
{
unsigned char TB7SEG[] = {	 0b00111111, 0b00000110, 0b01011011, 0b01001111,
				 0b01100110, 0b01101101, 0b01111101, 0b00000111, 
				 0b01111111, 0b01101111, 0b01110111, 0b01111100,
				 0b00111001, 0b01011110, 0b01111001, 0b01110001};
unsigned char display, sw;
		     DDRC = 0xFF;
		     DDRB = 0x00;
	    while (1)
	    {  sw = PINB;
	       sw &= 0x0F;
	       display = TB7SEG[sw]; 
	       PORTC = ~display;
	    }
return 0;
}

