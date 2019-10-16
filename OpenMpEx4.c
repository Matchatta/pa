#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int A[100];
    srand(1234); /* Set random seed */
    int i =0;
    int value =0;
    #pragma omp parallel num_threads(4)
    for (i=0; i < 100; i++){
        value = rand()%1000; /* Set each element randomly to 0-999 */
        if(value >= 500)
        {
            printf("%d. %d\n", i, value);
        }
    }
} 