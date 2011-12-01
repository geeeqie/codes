/*
 * blink
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/30
 * @description
 *   Blink an LED on PE6&PE7
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void delayms(uint16_t millis)
{
	while ( millis ) {
		_delay_ms(1);
		millis--;
	}
}

int main(void)
{
	DDRE |= 1<<PE6 | 1<<PE7;
	while (1) {
		//PORTA &= ~(1<<PA2); /* LED on */
		PORTE |= 1<<PE6|1<<PE7;
		delayms(100);
		// PORTA |= 1<<PA2; /* LED off */
		PORTE &= ~(1<<PE6|1<<PE7);
		delayms(900);
	}
	return 0;
}
