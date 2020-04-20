#ifndef TIMER__h__
#define TIMER__h__

#include <memory>
#include <functional>
#include "TimerExport.h"

class TIMER_EXPORT Timer
{
public:
    Timer(unsigned long intervalMillionSecs,std::function<void(void)> function, std::string funcTag,bool repeated = false);
    Timer(const Timer &) = delete;
    Timer(Timer &&) = delete;
    Timer &operator=(const Timer &) = delete;
    Timer &operator=(Timer &&) = delete;
    ~Timer();
public:
    void start();
    void stop(); 
private:
    class TimerPrivate;
    std::shared_ptr<TimerPrivate> _p;
};
#endif//Timer__h__