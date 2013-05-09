#include <avr/io.h>
//#include <avr/signal.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>

#include <avr/power.h>

#include <string.h>
#include <util/delay.h>
//#include "symbol_tbl.h"

#if 1
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
    PORTC=0;
  //  return;
  } else {
    PORTB&=~1;
  }

  hsync();

  char b[8];
  memcpy(b,"\x55\x55\xaa\xf0",4);

  if ( (line>50) && (line<90) ){
    _delay_us(3);//border
    char a=1;
    asm(
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"
        "out 0x0b,%0\n\t"
        "lsr %0\n\t"

        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        "out 0x0b,%1\n\t"
        "lsr %1\n\t"
        
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        "out 0x0b,%2\n\t"
        "lsr %2\n\t"
        
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"
        "out 0x0b,%3\n\t"
        "lsr %3\n\t"

        "out 0x0b,0\n\t"
        :
        :"r"(b[0]),"r"(b[1]),"r"(b[2]),"r"(b[3])
        :);
    return ;
  }//*/
        //,"r"(b[1]),"r"(b[2]),"r"(b[3])
  if ( (line>100) && (line<520) ){
    _delay_us(3);//border

    int k;
    for (k=0; k<16; k++) {
      //PORTB|=(1<<2);
      PORTD=1;
      _delay_loop_1(7);
      //_delay_us(1);//border
      PORTD=0;
      PORTC++;
    }
  }//*/
  //_delay_loop_1(4);
  //PORTB&=~(1<<2);
}

int main(void)
{

   wdt_disable();
   cli();

  TCCR1A=(1<<WGM11) | (1<<WGM10);
  TCCR1B=(1<<WGM13) | (1<<WGM12) | (1<<CS10);//CS == 0
  OCR1A=0x31b;
  TIMSK1=(1<<OCIE1A);
  power_timer1_enable();

  sei();

  DDRD=~0;
  PORTD=~0;

  DDRB=~0;
  //PORTB=1;

  DDRC=~0;
  PORTC=0;//=0xff;
  while(1) {};
/*
  set_sleep_mode(SLEEP_MODE_IDLE); 	

  while (1) {
    sleep_mode();
  }*/


  return(0);
}
