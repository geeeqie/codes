/*
 * Square Wave Generator
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/07/10
 * @description
 */

#include <mcs51reg.h>
#include "os.h"

void toggle_led(void)
{
	P1 = ~P1;
	add_timer(1024, toggle_led);
}

void toggle_led_task()
{
	add_timer(1024, toggle_led);
}

/* system entry */
void booted()
{
	add_task(toggle_led_task);
}
