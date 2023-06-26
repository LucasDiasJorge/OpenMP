#include <iostream>
#include <omp.h>

int main(int arg, char *argv[]) {
    
    if(argv[1] == NULL){
        std::cout << "Specify threads quantity after ./executable" << std::endl;
        return -1;
    }

    int threadNumbers = atoi(argv[1]);

    omp_set_num_threads(threadNumbers);

    std::cout << "---------- Threads action ----------" << std::endl;

    #pragma omp parallel
    {

        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " started." << std::endl;

        #pragma omp barrier


        std::cout << "Thread " << thread_id << " finished." << std::endl;
    }

    return 0;
}
