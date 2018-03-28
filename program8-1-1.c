#include <avr/io.h>
#include <avr/interrupt.h>
int main()
 { 
   DDRC = 0xFF;
   TIMSK0 = 0x01;
   TCCR0B = 0x04;
   TCCR0A = 0x00;
   TCNT0 = 194;
   sei();
  
  while(1);  
 }
 ISR(TIMER0_OVF_vect){
    TCNT0 = 194;
    PORTC =  ~ PORTC;
 }
