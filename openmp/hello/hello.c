#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void)
{
    #pragma omp parallel
    {
        printf("Hello OpenMP.\n");
    }
    return 0;
}
