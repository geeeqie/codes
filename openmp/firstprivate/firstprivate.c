#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
	int i;
	int a[] = {0,1,2};

	#pragma omp parallel for private(a)
	for (i = 0; i < 3; i++) {
		a[i] = 10+i;
	}
	
	for (i = 0; i < 3; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}
