#include<avr/io.h>
#include<avr/interrupt.h>
unsigned char TB7SEG[] = {	0b00111111,0b00000110,0b01011011,0b01001111,
							0b01100110,0b01101101,0b01111101,0b00000111,
							0b01111111,0b01101111,0b01110111,0b01111100,
							0b00111001,0b01011110,0b01111001,0b01110001 };					
unsigned char DISP, count;	
int main()
{	sei();
	DDRC = 0xFF;
	DDRD = 0x00;
	EICRA = 0x02;
	EIMSK = 0x01;
		
	DISP = TB7SEG[count];
        PORTC = (DISP);
						
	while(1);	   
}
ISR (INT0_vect)
{	count ++;
	DISP = TB7SEG[count];
        PORTC = (DISP);	
}

