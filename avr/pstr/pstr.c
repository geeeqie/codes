/*
 * pstr
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/11/19
 * @description
 *    Test PSTR in <avr/pgmspace.h> to store constant string 
 *    in the program space.
 */

#include <stdio.h>
#include <avr/pgmspace.h>

void main(void)
{
	printf(PSTR("I'm in the FLASH or RAM? It is a problem\n"));
}
