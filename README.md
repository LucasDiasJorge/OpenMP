# OpenMP
 learning how to use openmp in C++

1. Learning about critical sections

    It's a shared resource accessed/used by multiples threads at the same time, which can lead to race condiction and compromise data consistency.

2. Learning how to set threads number

    ```c
    omp_set_num_threads(int);
    ```

3. Learning how omp for works

    For paralellism between multiple threads.

4. The omp barrier 

    Identifies a synchronization point at which threads in a parallel region will wait until all other threads in that section reach the same point. Statement execution past the omp barrier point then continues in parallel.

    [Ref](https://www.ibm.com/docs/en/xl-c-aix/11.1.0?topic=processing-pragma-omp-barrier#:~:text=The%20omp%20barrier%20directive%20identifies,point%20then%20continues%20in%20parallel.)