#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {

    if(argv[1] == NULL){
        std::cout << "Specify threads quantity after ./executable" << std::endl;
        return -1;
    }

    int threadNumbers = atoi(argv[1]);

    omp_set_num_threads(threadNumbers);

    std::cout << "------ Without critical part ------" << std::endl;

    #pragma omp parallel
    {
        int threadID = omp_get_thread_num();
        std::cout << "Hello from thread " << threadID << std::endl;
    }

    std::cout << "------ With critical part ------" << std::endl;

    
    #pragma omp parallel // each core will create a threadId
    {
        int threadID = omp_get_thread_num();
        #pragma omp critical // avoid problems in the critical region, only core 0 works where
        {
            std::cout << "Hello from thread " << threadID << std::endl;
        }
    }

    return 0;
}