#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(void)
{
	int i, j;
	#pragma omp parallel sections
	{
		#pragma omp section
		for (i = 0; i < 5; i++) {printf("A");fflush(stdout);}
		#pragma omp section
		for (j = 0; j < 5; j++) {printf("B");fflush(stdout);}
	}
	printf("\n");

	#pragma omp parallel sections
	{
	#pragma omp section
		v = alpha();
	#pragma omp section
		w = beta();
	#pragma omp section
		y = delta();
	}
	x = gamma(v, w);
	epsilon(x, y);
    
    return 0;
}
