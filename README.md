# OpenMP
 learning how to use openmp in C++

1. Learning about critical sections

    It's a shared resource accessed/used by multiples threads at the same time, which can lead to race condiction and compromise data consistency.

2. Learning how to set threads number

    ```c
    omp_set_num_threads(int);
    ```