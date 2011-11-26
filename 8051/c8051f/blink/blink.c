/*
 * Blink the LEDS on P1_0,P1_1 
 * only test on C8051F340
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/26
 * @description
 */
#include <C8051F340.h>

void delay()
{
	unsigned long i, j;

	for (i = 0; i < 100UL; i++) {
		for (j = 0; j < 1000UL; j++) {
			__asm nop __endasm;
		}
	}
}

void main(void)
{
	/* Must disable watchdog first */
	PCA0MD &= ~0x40;

	/* enable crossbar, disable wake pull up, must set on C8051F340 */
	XBR1 = 0xc0;

	/* blink the LEDS on P1_0,P1_1 */
	while(1) {
		P1_0 = !P1_0;
		delay();
		P1_1 = !P1_1;
	}
}
