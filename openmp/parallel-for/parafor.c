#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int i, square[10];
    
    #pragma omp parallel for
    for (i = 1; i <= 10; i++) {
		square[i] = i*i;
    }

	for (i = 1; i <= 10; i++) {
		printf("%d ", square[i]);
	}
	printf("\n");
    
    return 0;
}
