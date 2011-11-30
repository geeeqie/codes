/*
 * uart
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/28
 * @description
 *   Echo the input character from uart0 on C8051F340
 *   the baudrate I set is 9600, but actually is 57600, so strange.
 *
 */
#include <C8051F340.h>

void uart_send(unsigned char ch)
{
	ES0 = 0;
	EA = 0;
	SBUF0 = ch;
	while (TI0 == 0) {
		;
	}
	TI0 = 0;
	ES0 = 1;
	EA = 1;
	P1_0 ^= 1;
}

void uart_isr(void) __interrupt(4)
{
	P1_1 ^= 1;
	if (!TI0) {
		unsigned char ch;
		RI0 = 0;
		ch = SBUF0;
		uart_send(ch);
	} else {
		TI0 = 0;
	}
}

void main(void)
{
	/* must disable watchdog first */
	PCA0MD &= ~0x40;

	P0MDOUT |= 0x10;
	XBR0 = 0x01;
	XBR1 = 0x40;
	XBR2 = 0x00;

	OSCICN |= 0x03;
	RSTSRC = 0x04;

	SCON0 = 0x10;

	TH1 = -109; //-(8*1024*1024 / 9600 / 2 / 4);
	CKCON &= ~0x0b;
	CKCON |= 0x09;
	TL1 = TH1;
	TMOD &= 0xf0;
	TMOD |= 0x20;
	TR1 = 1;

	/* enable global interrupt */
	EA = 1;
	ES0 = 1;

	while(1) {
		;
	}
}
