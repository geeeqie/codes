/*
 * Blink the LEDS on P0_0,P0_1 
 * only test on CC2530
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 */
#include "../cc2530_sfr.h"

void delay()
{
	unsigned int i, j;

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {
			__asm nop __endasm;
		}
	}
}

void main(void)
{
	/* must add for cc2530 */
	P0SEL &= 0xFC;
	P0DIR |= 0x03;

	/* blink the LEDS on P0_0,P0_1 */
	while(1) {
		P0 = 0x03;
		delay();
		P0 = 0x00;
		delay();
	}
}
