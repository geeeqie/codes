/*
 * usart
 *
 * test CC2530's usart 
 *   - send to PC the ASCII character 'A'-'z'
 *   - echo the character from PC
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 */
#include "../cc2530_sfr.h"
#include <stdint.h>

void init_usart()
{
	PERCFG = 0x00;
	P0SEL = 0x3c; // 0011 1100
	U0CSR |= 0x80;
	U0GCR |= 11;
	U0BAUD = 216; // set baudrate 115200
	UTX0IF = 1;
	U0CSR |= 0x40;
	EA = 1; URX0IE = 1; //IEN0 |= 0x84; // 1000 0100
}

void usart_putchar(char ch)
{
	U0DBUF = ch;
	while (UTX0IF == 0)
		__asm nop __endasm;
	UTX0IF = 0;
}

void usart_isr() __interrupt(URX0_VECTOR)
{
	char ch;

	URX0IF = 0;
	ch = U0DBUF;
	usart_putchar(ch);
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
	char ch;
	/* clear sleep timer interrupt flag */
	STIF = 0;
	addToSleepTimer(1);
	for (ch = 'A'; ch <= 'z'; ch++) {
		usart_putchar(ch);
	}
	usart_putchar('\n');
	usart_putchar('\r');
}

void main(void)
{
	/* set main clock source to 32MHz */
	SLEEPCMD &= ~0x04;
	__asm nop __endasm;
	while(!(SLEEPSTA & 0x40));
	CLKCONCMD &= ~0x47;
	SLEEPCMD |= 0x04; 

	/* enable sleeptimer interrupt */
	STIE = 1;
	/* enable global interrupt */
	EA = 1;

	init_usart();

	addToSleepTimer(1);

	while(1) {
		/* set to PM2 */
		SLEEPSTA &= ~0x03;
		SLEEPSTA |= 2;
		PCON |= 0x01;
		__asm nop __endasm;
	}
}
