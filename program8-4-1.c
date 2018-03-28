#include <avr/io.h>
#include <avr/interrupt.h>
int main()
{  DDRD = 0xFF;
   TIMSK1 = 0x01;
   TCCR1B = 0x04;
   TCCR1A = 0x00;
   TCNT1 = 63974;
   sei();
  
  while(1);  
}
 ISR(TIMER1_OVF_vect)
{
    TCNT1 = 63974;
    PORTD =  ~ PORTD;
}
