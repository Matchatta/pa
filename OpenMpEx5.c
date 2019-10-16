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
    i=0;
    #pragma omp parallel private(i) shared(sum) num_threads(4)
    {
        int chunkSize = 100/4;
        int tid = omp_get_thread_num();
        int start = tid*chunkSize;
        int end = (tid + 1)*chunkSize-1;
        for(i= start; i<=end; i++){
            #pragma omp critical
            sum += A[i];
        }
    }
    printf("sum = %d\n", sum);
} 