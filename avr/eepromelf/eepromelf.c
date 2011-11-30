/*
 * eepromelf 
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/19
 * @description
 *    explore how to manipulate EEPROM in c program.
 */

#include <stdio.h>
#include <avr/eeprom.h>

uint8_t some_data[8] EEMEM = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07}; /* It's OK */

void main(void)
{
	uint8_t RAMval;

	some_data[0] = 0xab; /* no effect */
	RAMval = some_data[1]; /* Is this make sense? no tested yet */

	while(1);
}
