/*
 * timer
 *
 * set timer2 for C8051F340
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/26
 * @description
 */
#include <C8051F340.h>

void timer2_isr(void) __interrupt(5)
{
	/* clear timer2 interrupt flag */
	TF2H = 0;

	/* toggle */
	P1_0 ^= 1;
	P1_1 ^= 1;
}

void main(void)
{
	/* must disable watchdog first */
	PCA0MD &= ~0x40;
	/* must enable crossbar, disable weakpull */
	XBR1 = 0xc0;

	/* set timer2 */
	TMR2RLL = 0xc6; /* timer2 reload low byte */
	TMR2RLH = 0x06; /* timer2 reload high byte */
	TMR2CN = 0x04; /* enable timer2 */
	
	/* enable timer2 interrupt */
	IE = 0x20;
	/* enable global interrupt */
	EA = 1;

	while(1) {
		;
	}
}
