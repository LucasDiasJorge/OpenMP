#include <iostream>
#include <omp.h>

int main() {

    std::cout << "------ Without critical part ------" << std::endl;

    #pragma omp parallel
    {
        std::cout << "Hello from thread" << std::endl;
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