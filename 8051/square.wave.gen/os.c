/*
 * os.c
 *
 * @author Geeeqie <geeeqie>@gmail.com>
 * @date 2011/07/10
 * @description
 */

#include <reg52.h>
#include "os.h"

/**************** System Services ********************/

unsigned long jitter = 0;
unsigned long fired = 0;

void init_hw_timer()
{
	TMOD |= 0x01;
	TH0 = 0xFB;
	TL0 = 0xFF;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}

#define NR_TIMER_MAX 4
struct timer {
	unsigned char is_on;
	unsigned long fired_time;
	void (*func)(void);
};
struct timer timer[NR_TIMER_MAX];

enum {
	TIMER_OFF = 0,
	TIMER_ON,
};

void hw_timer_isr() interrupt 1 using 1
{
	unsigned char i;

	TH0 = 0xFB;
	TL0 = 0xFF;
	jitter++;

	for (i = 0; i < NR_TIMER_MAX; i++) {
		if (timer[i].is_on && jitter > timer[i].fired_time) {
			timer[i].is_on = TIMER_OFF;
			timer[i].func();
		}
	}
}

void init_timer()
{
	unsigned char i;

	for (i = 0; i < NR_TIMER_MAX; i++) {
		timer[i].is_on = TIMER_OFF;
	}
	init_hw_timer();
}

/*
 * @param t: delay in ms
 * @param func: invoke the func when timer fired
 *
 */
unsigned char add_timer(unsigned long t, void (*func)(void))
{
	unsigned char i;
	for (i = 0; i < NR_TIMER_MAX; i++) {
		if (timer[i].is_on == TIMER_OFF) {
			timer[i].is_on = TIMER_ON;
			timer[i].fired_time = jitter + t;
			timer[i].func = func;
			return SUCCESS;
		}
	}
	return FAIL;
}

struct task {
	unsigned char state;
	void (*func)(void);
};

#define NR_TASK_MAX 5
struct task task[NR_TASK_MAX];
enum {
	TASK_IDLE = 0,
	TASK_READY,
};

void init_task()
{
	unsigned char i;
	for (i = 0; i < NR_TASK_MAX; i++) {
		task[i].state = TASK_IDLE;
	}
}

unsigned char add_task(void (* func)(void))
{
	unsigned char i;
	for (i = 0; i < NR_TASK_MAX; i++) {
		if (task[i].state == TASK_IDLE) {
			task[i].state = TASK_READY;
			task[i].func = func;
			return SUCCESS;
		}
	}
	return FAIL;
}

void booted();

void main(void)
{
	unsigned char i;

	init_timer();
	init_task();

	booted();
	while (1) {
		for (i = 0; i < NR_TASK_MAX; i++) {
			if (task[i].state == TASK_READY) {
				task[i].state = TASK_IDLE;
				task[i].func();
			}
		}
	}
}
