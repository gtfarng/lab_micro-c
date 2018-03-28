#include <avr/io.h>
int main()
{ 
   DDRB = 0xFF;
   TIMSK1 = 0x00;
   TCCR1A = 0x12; 
   TCCR1B = 0x04;
   OCR1A = 780;
  
  while(1);
  
}
