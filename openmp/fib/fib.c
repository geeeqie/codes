#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
	int i;
	int fib[10] = {1,1};

	#pragma omp parallel for
	for (i = 2; i < 10; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		printf("%d ", fib[i]);
	}
	printf("\n");
	return 0;
}
