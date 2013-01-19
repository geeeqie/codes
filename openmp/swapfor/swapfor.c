#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(void)
{
    int i,j;
	const int m = 4, n = 5;
	int a[m][n];
    
	for (i = 0; i < n; i++) {
		a[0][i] = 1;
	}

	#pragma omp parallel for private(i)
	for (j = 0; j < n; j++) {
		for (i = 1; i < m; i++) {
			a[i][j] = a[i-1][j] * 2;
		}
    }

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}
    
    return 0;
}
