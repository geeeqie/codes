#include <stdio.h>
#include <omp.h>
#include <unistd.h>

struct task_struct {
	int task;
	struct task_struct *next;
};

void process(int task) {}

int main(void)
{
	struct task_struct *p = NULL;
	struct task_struct *job = NULL;

	#pragma omp parallel private(p)
	while(job != NULL) {
		#pragma omp critical
		{
			p = job;
			job = job->next;
		}
		process(p->task);
	}
    return 0;
}
