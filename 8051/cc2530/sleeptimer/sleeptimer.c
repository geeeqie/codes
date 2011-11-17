/*
 * sleeptimer
 *
 * set sleep timer for CC2530
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 */
#include "../cc2530_sfr.h"
#include <stdint.h>

void toggle()
{
	static uint8_t on = 0;
	
	if (!on) {
		P0_0 = 1;
		P0_1 = 0;
		on = 1;
	} else {
		P0_0 = 0;
		P0_1 = 1;
		on = 0;
	}
}

void addToSleepTimer(uint16_t sec)
{
	uint32_t sleepTimer = 0;

	sleepTimer |= ST0;
	sleepTimer |= (uint32_t)ST1 <<  8;
	sleepTimer |= (uint32_t)ST2 << 16;

	sleepTimer += ((uint32_t)sec * (uint32_t)32768);

	ST2 = (uint8_t)(sleepTimer >> 16);
	ST1 = (uint8_t)(sleepTimer >> 8);
	ST0 = (uint8_t) sleepTimer;
}

void sleep_timer_isr(void) __interrupt(5)
{
	/* clear sleep timer interrupt flag */
	STIF = 0;
	addToSleepTimer(1);
	toggle();
}

void main(void)
{
	P0SEL = 0xFC;
	P0DIR = 0x03;
	P0 = 0x00;

	/* enable sleeptimer interrupt */
	STIE = 1;
	/* enable global interrupt */
	EA = 1;

	addToSleepTimer(1);
	while(1) {
		/* set to PM2 */
		SLEEPSTA &= ~0x03;
		SLEEPSTA |= 2;
		PCON |= 0x01;
		__asm nop __endasm;
	}
}
