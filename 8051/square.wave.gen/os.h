/*
 * Os.h
 *
 * @author Geeeqie <geeeqie@gmail.com>
 * @date 2011/07/10
 * @description
 */

#ifndef _OS_H
#define _OS_H

enum {
	SUCCESS = 0,
	FAIL = 1,
};

/*
 * @param t: delay in ms
 * @param func: invoke the func when timer fired
 *
 */
unsigned char add_timer(unsigned long t, void (*func)(void));

/*
 * @param func: task function
 */
unsigned char add_task(void (* func)(void));

/*
 * application entry
 */
void booted();

#endif
