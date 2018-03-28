#include <avr/io.h>
int main()
 { 
   DDRD = 0xFF;
   TIMSK0 = 0x00;
   TCCR0B = 0x04;
   TCCR0A = 0x12;
   OCR0A = 62;
   TCNT0 = 0;
  
  while(1);
  
}
