#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"

int main(int argc, char *argv[])
{
    auto testFun = [](std::chrono::system_clock::time_point tt){std::cout<<"test func executed!"<<(std::chrono::system_clock::now()-tt).count()<<std::endl;};
    auto now = std::chrono::system_clock::now();
    Timer tm(1000,std::bind(testFun,now),"testFunc",true);
    tm.start();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    tm.stop();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    tm.start();
    std::this_thread::sleep_for(std::chrono::seconds(5));


    return 0;
}