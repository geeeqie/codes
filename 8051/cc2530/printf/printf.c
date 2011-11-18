/*
 * printf
 *
 * printf works with CC2530's usart 
 * performs like a shell with no command
 * the key is to implement putchar()
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 */
#include "../cc2530_sfr.h"
#include <stdint.h>
#include <stdio.h>

char line[64];
uint8_t len = 0;

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

void putchar(char c)
{
	U0DBUF = c;
	while (UTX0IF == 0)
		__asm nop __endasm;
	UTX0IF = 0;
}

void shell()
{
	line[len - 1] = 0; /* [len - 1] is '\r' */
	printf("%s: command not found\r\n", line);
	printf("# ");
}

void usart_isr() __interrupt(URX0_VECTOR)
{
	char ch;

	URX0IF = 0;
	ch = U0DBUF;
	/* echo the input character */
	putchar(ch);

	/* read a line */
	line[len++] = ch;
	if (ch == '\r') {
		printf("\r\n"); /* for minicom */
		shell();
		len = 0;
	}
}

void main(void)
{
	/* set main clock source to 32MHz */
	SLEEPCMD &= ~0x04;
	__asm nop __endasm;
	while(!(SLEEPSTA & 0x40));
	CLKCONCMD &= ~0x47;
	SLEEPCMD |= 0x04; 

	/* enable global interrupt */
	EA = 1;

	init_usart();

	printf("# ");
	while(1) {
		/* set to PM2 */
		SLEEPSTA &= ~0x03;
		SLEEPSTA |= 2;
		PCON |= 0x01;
		__asm nop __endasm;
	}
}
