#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i, sum = 0;
    
    #pragma omp parallel for
    for (i = 1; i <= 100; i++) {
		#pragma omp critical
		{
			sum += i;
		}
    }
	printf("sum=%d\n", sum);
    
    return 0;
}
