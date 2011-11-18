/*
 * radio
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/18
 * @description
 *     Test CC2530's radio, print the received message in bytes,
 *     send back the same message, behaves like a 'echo' program.
 *
 *     NOTE: only receive message with PAN ID 0x22
 *
 */
#include "../cc2530_sfr.h"
#include <stdint.h>
#include <stdio.h>

void init_usart()
{
	PERCFG = 0x00;
	P0SEL = 0x3c; // 0011 1100
	U0CSR |= 0x80;
	U0GCR |= 11;
	U0BAUD = 216; // set baudrate 115200
	UTX0IF = 1;
	U0CSR |= 0x40;
}

void putchar(char c)
{
	U0DBUF = c;
	while (UTX0IF == 0) {
		__asm nop __endasm;
	}
	UTX0IF = 0;
}

void rf_init()
{
	FRMCTRL0 |= (0x20 | 0x40); /* AUTO_ACK | AUTO_CRC */

	TXFILTCFG = 0x09;
	AGCCTRL1 = 0x15;
	FSCAL1 = 0x00;

	/* enable RXPKTDONE interrupt */
	RFIRQM0 |= BV(6);
	/* enable general RF interrupts */
	IEN2 |= BV(0);

	FREQCTRL = 0x0b; /* channel 11 */

	SHORT_ADDR0 = 0x04;
	SHORT_ADDR1 = 0x00;
	PAN_ID0 = 0x22; /* MUST set, or even can't receive broadcast message  */
	PAN_ID1 = 0x00;

	RFST = 0xec; /* ISFLUSHRX */
	RFST = 0xe3; /* ISRXON */
}

static uint8_t buf[128];
static uint8_t len;

void rf_isr(void) __interrupt(RF_VECTOR)
{
	uint8_t e, i;

	e = EA;
	EA = 0; /* disable global interrupt */

	if (RFIRQF0 & BV(6)) {
		len = RFD;
		len &= 0x7f;
		for (i = 0; i < len; i++) {
			buf[i] = RFD;
		};

		S1CON = 0; /* clear general RF interrupt flag */
		RFIRQF0 &= ~BV(6); /* clear RXPKTDONE interrupt */
	}
	EA = e; /* restore global interrupt state */
}

void tx()
{
	uint8_t i;

	RFST = 0xe3; /* ISRXON */
	/* wait for SFD not active and TX_Active not active */
	while (FSMSTAT1 & (BV(1) | BV(5))); /* TX_ACTIVE | SFD */
	RFIRQM0 &= ~BV(6); /* disable RXPKTDONE interrupt */
	IEN2 &= ~BV(0); /* disable general RF interrupts */

	RFST = 0xee; /* ISFLUSHTX */
	RFIRQF1 = ~BV(1); /* clear TXDONE interrupt */
	RFD = len; /* the first byte to TX is the length of the frame */
	for (i = 0; i < len; i++) {
		RFD = buf[i];
	}

	/* trun on RX interrupt */
	RFIRQM0 |= BV(6);
	IEN2 |= BV(0);

	RFST = 0xe9; /* ISTXON */
	while (!(RFIRQF1 & BV(1))); /* waiting for transmission to finish */
	RFIRQF1 = ~BV(1); /* clear TXDONE interrupt */
}

void main(void)
{
	EA = 0;
	/* set main clock source to 32MHz */
	SLEEPCMD &= ~0x04;
	while(!(SLEEPSTA & 0x40));
	__asm nop __endasm;
	CLKCONCMD &= ~0x47;
	SLEEPCMD |= 0x04; 

	init_usart();
	rf_init();
	EA = 1; /* enable global interrupt */

	while(1) {
		if (len > 0) {
			uint8_t i;
			printf("[%d] ", len);
			for (i = 0; i < len; i++) {
				printf("%02x ", buf[i]);
			}
			printf("\n\r");
			/* transmit the received message */
			tx();
			len = 0;
		}
	}
}
