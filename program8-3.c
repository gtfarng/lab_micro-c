#include<avr/io.h>
#include<avr/interrupt.h>
unsigned char TIME0x,TIMEx0;
unsigned char TB7SEG[] = {	0b00111111,0b00000110,0b01011011,0b01001111,
				0b01100110,0b01101101,0b01111101,0b00000111,
				0b01111111,0b01101111,0b01110111,0b01111100,
				0b00111001,0b01011110,0b01111001,0b01110001 };
int main(void)
{	TIME0x = 0; 
	TIMEx0 = 0; 
	
	DDRB = 0b11111101; 
	DDRC = 0xFF; 
	DDRD = 0xFF; 
	
	PORTD = ~TB7SEG[0]; 
	PORTC = ~TB7SEG[0]; 
	PORTB = 0b11111110;
	
	TCCR1A = 0x00; 
	TCCR1B = 0x04; 
	TIMSK1 = 0x01; 
	
	cli();
	TCNT1 = 63583;
	sei(); 
	
	while(1);
}

ISR(TIMER1_OVF_vect)
{
	TCNT1 = 63583;
	TIME0x++; 
	if(TIMEx0 < 5 && TIME0x == 10)
        { 
		TIME0x = 0;
		TIMEx0++; 
	}
	
	if(TIMEx0 == 5 && TIME0x == 1)
        { 
		TIME0x = 0; 
		TIMEx0 = 0;
		PORTB = PORTB & 0x01;
		PORTD = ~PORTD; 
	}
	PORTB = PORTB & 0x80; 
	PORTC = ~TB7SEG[TIMEx0]; 
	PORTD = ~TB7SEG[TIME0x]; 
}
