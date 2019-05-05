#include <iostream>

#include "processingunit.h"

#include <thread>
#include <chrono>
#include <time.h>
#include <cstdlib>
#include <iostream>

std::mutex m;

void output(std::vector<double> vals){
    std::lock_guard<std::mutex> lock(m);
    double sum=0.0;
    for (double v: vals) sum+=v;
    std::cout << sum << std::endl;
}

std::vector<double> randvec(size_t n){
    std::vector<double> v;
    v.reserve(n);
    for (size_t i=0;i<n;i++) v.push_back( (double)(rand() % 1000)/1000.0 );
    return v;
}

int main()
{
    gs::BaseProcessingUnit< std::vector<double> > *proc=new gs::BaseProcessingUnit< std::vector<double> >(output);

    for(size_t i=0;i<10;i++)
        proc->push(randvec(100), i==9);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "finished" << std::endl;

    return 0;
}
