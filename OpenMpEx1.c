#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int A[100];
    int T =4;
    srand(1234); /* Set random seed */
    int i =0;
    for (i=0; i < 100; i++){
        A[i] = rand()%1000; /* Set each element randomly to 0-999 */
    }
    #pragma omp parallel private(i) num_threads(T)
    {
        int chunkSize = 100/T;
        int tid = omp_get_thread_num();
        int start = tid*chunkSize;
        int end = (tid + 1)*chunkSize-1;
        for(i= start; i<=end; i++){
            A[i] = A[i]*10;
            printf("%d. %d\n", i+1, A[i]);
        }
    }
} 