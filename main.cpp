#include <iostream>

#include "threadfifoqueue.h"

#include <thread>
#include <time.h>
#include <cstdlib>
#include <iostream>


gs::ThreadFIFOQueue<int> q;


void putrand(int num=10){
    for(int k=0;k<num;k++)
        q.push(k);//rand()%100);
}

int main()
{
    srand (time(NULL));

    std::thread t(putrand,10);

    for(int i=0;i<10;i++) {
        std::cout << "get: " << q.pop() << std::endl;
    }

    t.join();




    return 0;
}
