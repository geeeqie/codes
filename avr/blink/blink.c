/*
 * Blink a LED
 * @author Geeeqie <geeeqie@gmail.com>
 *
 */
#define F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>

void delayms(uint16_t millis) {
        uint16_t loop;
        while ( millis ) {
                _delay_ms(1);
                millis--;
        }
}

int main(void) {
        DDRD |= 1<<PD5 | 1<<PD6 | 1<<PD7; /* set PA1 to output */
        while(1) {
                //PORTA &= ~(1<<PA2); /* LED on */
		PORTD = ~0;
                delayms(100);
                // PORTA |= 1<<PA2; /* LED off */
		PORTD = 0;
                delayms(900);
        }
        return 0;
}
