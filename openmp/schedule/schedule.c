#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(void)
{
    int i, j, n = 5;
    
    #pragma omp parallel for private(j) schedule(static)
    for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			printf("(%d,%d) ", i, j);
		}
		printf("\n");
    }
    
    return 0;
}
