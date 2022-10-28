/*
 * RGB_Lamp.c
 *
 *  Author: Sparrow-hawk
 *  Email:	sparrow-hawk@hotmail.com
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

#include "LED_Func.h"

/*
 *
 * RED		PB3		OCR0A
 * GREEN	PB4		OCR0B
 * BLUE		PD7		OCR2A
 *
 * 255 - LED OFF
 * 0   - LED FULL ON
 *
 */

#define T0_TICKS_PER_SECOND(T)	(F_CPU / 8UL / 256UL) / (T)		

volatile uint8_t gTimer1 = 0;
volatile uint8_t gTimer2 = 0;

volatile uint8_t gR = 8;
volatile uint8_t gG = 8;
volatile uint8_t gB = 8;


int main(void)
{
	DDRB = _BV(PB0) | _BV(PB3) | _BV(PB4);
	DDRD = _BV(PD7);
	
	/* Timer 0 config for PWM OCR0A & OCR0B */
	TCCR0A = _BV(WGM00) | _BV(WGM01) | _BV(COM0A1) | _BV(COM0B1);
	TCCR0B = _BV(CS01);
	TIMSK0 = _BV(TOIE0);
	
	OCR0A = LED_LEVEL(gR); 
	OCR0B = LED_LEVEL(gG);
	
	/* Timer 2 config for PWM OCR2A */
	TCCR2A = _BV(WGM00) | _BV(WGM01) | _BV(COM2A1);
	TCCR2B = _BV(CS01);
	TIMSK2 = _BV(TOIE2);
	
	OCR2A = LED_LEVEL(gB);

	sei();	
	
	uint8_t step = 0;
    while (1) 
    {
		if (!gTimer1)
		{	
			gTimer1 = T0_TICKS_PER_SECOND(2);
			
			PORTB ^= _BV(PB0);
		}
		
		if (!gTimer2)
		{
			gTimer2 = T0_TICKS_PER_SECOND(10);	
			
			gR = LED_funcR(step);
			gG = LED_funcG(step);
			gB = LED_funcB(step);
			
			step += 1;
		}
    }
}

ISR(TIMER0_OVF_vect)
{
	// Interrupt routine for update the OCR0A & OCR0B
	
	// 1 MHz / 8 / 256 = 488.28125 Hz
	
	uint8_t t = gTimer1;
	if (t)
	{
		gTimer1 = --t;
	}
	
	t = gTimer2;
	if (t)
	{
		gTimer2 = --t;
	}
	
	OCR0A = LED_LEVEL(gR);
	OCR0B = LED_LEVEL(gG);
}

ISR(TIMER2_OVF_vect)
{
	// Interrupt routine for update the OCR2A
	OCR2A = LED_LEVEL(gB);
}