/*
 * uart
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/17
 * @description
 *   test Atmega64's UART0
 *     - send to PC the ASCII character 'A'-'z'
 *     - echo the character from PC
 *     - test in minicom with baudrate 115200 8in1,no parity,no hw flow control
 *
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 14745600UL
#define BAUD 115200UL

/* copy from atmega64's datasheet */
#define MYUBRR (F_CPU/16/BAUD - 1)

void init_uart()
{
	/* set baud rate */
	UBRR0H = (uint8_t)MYUBRR>>8;
	UBRR0L = (uint8_t)MYUBRR;

	/* enable rx */
	UCSR0B = 1<<RXEN0;
	/* enable tx */
	UCSR0B |= 1<<TXEN0;
	/* enable rx interrupt */
	UCSR0B |= 1<<RXCIE0;

	/* set frame format: 8 data, 1 stop bit */
	UCSR0C = 3<<UCSZ00;
}

void uart_putchar(char ch)
{
	while (!(UCSR0A & (1<<UDRE0))) {
		;
	}
	UDR0 = ch;
}

ISR(USART0_RX_vect)
{
	char ch;

	PORTE ^= 1<<PE6 | 1<<PE7;
	ch = UDR0;
	uart_putchar(ch);
}

ISR(TIMER1_COMPA_vect)
{
	char ch;

	for (ch = 'A'; ch <= 'z'; ch++) {
		uart_putchar(ch);
	}
	uart_putchar('\n');
	uart_putchar('\r');
	TCNT1 = -0xE100; /* 1HZ with 14.7456MHz crystal, can calculated by http://www.et06.dk/atmega_timers */
}

void main(void)
{
	DDRE |= 1<<PE6 | 1<<PE7;

	TCCR1B = 1<<CS12; /* no prescaler */
	TIMSK = 1<<OCIE1A;

	init_uart();

	sei();

	while(1) {
		;
	}
}
