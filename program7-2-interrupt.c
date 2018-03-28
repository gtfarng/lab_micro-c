#include<avr/io.h>
#include<avr/interrupt.h>
unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};
unsigned char SWITCH;
int main ()
{
	sei();
        PCICR = 0x01;
        PCMSK0 = 0x0F;
	DDRB = 0x00;
	DDRC = 0xFF;
	SWITCH = PINB;
	SWITCH &= 0x0F;
        
	PORTC = ~(TB7SEG[SWITCH]);
	while(1);
}
ISR(PCINT2_vect){
	 SWITCH = PINB;
	 SWITCH &= 0x0F;
	 PORTC = ~(TB7SEG[SWITCH]);
}
