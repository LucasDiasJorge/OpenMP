#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {

    if(argv[1] == NULL){
        std::cout << "Specify threads quantity after ./executable" << std::endl;
        return -1;
    }

    int threadNumbers = atoi(argv[1]);

    omp_set_num_threads(threadNumbers);

    const int N = 10;
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    std::cout << "---------- Threads action ----------" << std::endl;

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        std::cout << "Thread " << omp_get_thread_num() << std::endl;
        sum += array[i];
    }

    std::cout << "---------- Threads action ----------" << std::endl;


    std::cout << "Sum: " << sum << std::endl;

    return 0;
}