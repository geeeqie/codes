/*
 * Timer
 *
 * @author Qiu Ying <qiuying@mail.nwpu.edu.cn>
 * @date 2011/11/30
 * @description
 *   Blink an LED on PE6&PE7 with Timer1A at 1Hz
 *   timer1 interrupt signals at 1kHz, interval 1ms.
 *   The external crystal is 14.7456M
 *
 */

#define F_CPU 14745600UL
#define KHZ 1024UL

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
	static uint16_t c;

	if (c++ == KHZ) {
		PORTE ^= 1<<PE6|1<<PE7; /* Toggle LED */
		c = 0;
	}

	TCNT1 = -((uint16_t)(F_CPU/KHZ)); /* for 1kHz, f_clock=14.7456MHz */
}

int main(void)
{
	DDRE |= 1<<PE6 | 1<<PE7;

	/* init Timer1A */
	TCCR1B = 1<<CS10; /* no prescaler */
	TIMSK = 1<<OCIE1A;

	sei();

	while (1) {
		;
	}
	return 0;
}
