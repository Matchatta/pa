#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int A[100];
    srand(1234); /* Set random seed */
    int i =0;
    int max_value =0;
    for (i=0; i < 100; i++){
        A[i] = rand()%1000; /* Set each element randomly to 0-999 */
    }
    #pragma omp parallel for reduction(max:max_value)
    for (i=0; i < 100; i++){
        if(A[i] > max_value)
        {
            max_value = A[i];  
        }
    }
    printf("%d\n", max_value);    
} 