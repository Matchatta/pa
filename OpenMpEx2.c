#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int A[100];
    srand(1234); /* Set random seed */
    int i =0;
    int sum =0;
    for (i=0; i < 100; i++){
        A[i] = rand()%1000; /* Set each element randomly to 0-999 */
    }
    #pragma omp parallel for reduction(+:sum)
    for (i=0; i < 100; i++){
        sum += A[i];
    }
    printf("%d\n", sum);    
} 