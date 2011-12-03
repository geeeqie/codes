/*
 * extint - external interrupt
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 *     test external interrupt. when a external interrupt signals
 *     toggle a LED.
 *
 *     PD7 wire to PD0;
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 14745600UL
#include <util/delay.h>

ISR(INT0_vect)
{
	PORTE ^= 1<<PE6;
}

void main(void)
{
	cli();
	DDRE |= 1<<PE6 | 1<<PE7;
	DDRD |= 1<<PD1;

	/* ISC01=1,ISC00=0, the falling edge of INT0 generates asynchronously an interrupt request. */
	EICRA = 1<<ISC01; 
	EIMSK = 1<<INT0;
	sei();

	while(1) {
		_delay_ms(1000);
		PORTD ^= 1<<PD1;
		PORTE ^= 1<<PE7;
	}
}
