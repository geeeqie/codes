#include <avr/io.h>
#include <avr/sleep.h>

int main(void)
{
	sleep_enable();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);

	while(1)
	{
		ADCSRA &= ~(1<<ADEN);
		PRR0 |= ~0;
		sleep_cpu();
	}
	return 0;
}
