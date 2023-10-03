// use openmp to parallelize a for loop
// compile with: g++ -std=c++11 -fopenmp parallel.cpp -o parallel
// run with: ./parallel

#include <iostream>
#include <omp.h>

int main() 
{
    int n = 1000;
    int sum = 0;
    int i;

    // write in vectorized form


    #pragma omp parallel for reduction(+:sum)
    // 
    for (i = 0; i < n; i++) 
    {
        printf("thread: %d - i = %d \n", omp_get_thread_num(), i);
    }
    return 0;
}