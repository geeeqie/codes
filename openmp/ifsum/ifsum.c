#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main(void)
{
    int i;
	int sum = 0;
	int n;

	scanf("%d", &n);
    
    #pragma omp parallel for if (n > 10000)
    for (i = 1; i <= n; i++) {
		#pragma omp critical
		sum += i;
    }
	printf("sum=%d\n", sum);
    
    return 0;
}
