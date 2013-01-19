#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
	int i, j;

	#pragma omp parallel for private(j)
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("(%d %d)", i, j);
		}
	}
	printf("\n");
	return 0;
}
