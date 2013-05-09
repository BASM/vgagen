#include <avr/io.h>
//#include <avr/signal.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>

#include <avr/power.h>

#include <string.h>
#include <util/delay.h>
//#include "symbol_tbl.h"

#if 0
#define vsync() {PORTB&=~1; _delay_us(4); PORTB|=1;}
#define hsync() {PORTB&=~2; _delay_us(4); PORTB|=2;}
#else
#define vsync() {PORTB|=1; _delay_us(64); PORTB&=~1;}
#define hsync() {PORTB|=2; _delay_us(4); PORTB&=~2;}
#endif

int line=0;

ISR(TIMER1_COMPA_vect)
{      

  if (line>520) line=0;
  line++;
  if (line<3) {
    PORTB|=1;
  //  return;
  } else {
    PORTB&=~1;
  }

  hsync();

  if ( (line>50) && (line<500) ){
    _delay_us(2);//border

    PORTB|=(1<<2);
    _delay_us(6);
    PORTB&=~(1<<2);

    PORTB&=~(1<<3);
    PORTB|=(1<<3);
  }

 // int i;
 // hsync();
 // _delay_us(4);

 // if ((i>100)&&(i<200))   PORTB|=(1<<2);
//  _delay_us(20);
 // if ((i>100)&&(i<200))   PORTB&=~(1<<2);
  //if ((i>22)&&(i<502))   PORTB&=~(1<<2);

  //_delay_us(3);
}
//         */

int main(void)
{

   wdt_disable();
   cli();
 
  TCCR1A=(1<<WGM11) | (1<<WGM10);
  TCCR1B=(1<<WGM13) | (1<<WGM12) | (1<<CS10);//CS == 0
  OCR1A=0x31b;
  TIMSK1=(1<<OCIE1A);
  power_timer1_enable();
              /*
               *
  TCCR0 = 0x00; //stop
  TCNT0 = 0xC3; //set count, One VGA line 31.77us
  TCCR0 = 1<<CS01; //start timer with prescaler select 1/8
  TIMSK = 1<<TOV0; //enable interrupt from Timer0 overflow
  // */
  sei();

   _delay_ms(1000);

    DDRB=~0;
    PORTB=1;

    while (1) {
      //PORTB+=1;
      _delay_ms(1);
      //vsync();
    }


    return(0);
}
