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

const char byte[2] PROGMEM={0x55,0xee};

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

  char b;
  if (line%2) {
    b=byte[0];
    b=byte[1];
  }

  int i=0;
  if ( (line>40) && (line<520) ){
    _delay_us(2);//border

    int k;
    for (k=0; k<16; k++) {
      PORTB|=(1<<2);
      _delay_loop_1(10);
      //_delay_us(1);//border
      //PORTB&=~(1<<2);
      PORTC++;
    }
  }
  //_delay_loop_1(4);
  PORTB&=~(1<<2);
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

  DDRB=~0;
  PORTB=1;

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
