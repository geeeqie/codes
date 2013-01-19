#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STR "I'm in the heap"

int main(void)
{
	int i;
	int local_array[3] = {1,2,3};
	char *str_ptr;

	str_ptr = malloc(sizeof(STR));
	strcpy(str_ptr, STR);
	#pragma omp parallel for
	for (i = 0; i < 2; i++) {
		printf("[%d] i=%d, local_array=[%d,%d,%d], str=%s [0x%08X]\n",
				omp_get_thread_num(),
				i,
				local_array[0], local_array[1], local_array[2],
				(uint32_t)str_ptr, str_ptr);
	}
	return 0;
}
