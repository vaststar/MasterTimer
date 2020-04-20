#include "Timer.h"

#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>
#include <sstream>
#include <ostream>

static void OutPut(std::string messages){std::ostringstream _oss; _oss << messages;std::cout<<_oss.str()<<std::endl;};

class Timer::TimerPrivate
{
public:
    TimerPrivate(unsigned long intervalMillionSecs, bool repeated, std::function<void(void)> function, std::string funcTag)
        :m_intervalMillionSecs(intervalMillionSecs),m_isRepeated(repeated),m_function(std::move(function)),m_functionTag(std::move(funcTag))
        ,m_isStopped(false),m_isStarted(false),m_isInTerminate(false)
    {

    }
    ~TimerPrivate()
    {
        OutPut("deconsruct timer:["+this->m_functionTag+"]");
        if(!m_isStopped.load())
        {
            m_isStopped.store(false);
        }
        if(!m_isInTerminate.load())
        {
            m_isInTerminate.store(true);
        }
    }
    void start()
    {
        if(m_isInTerminate.load() || (m_isStarted.load() && !m_isStopped.load()))
        {
            return;
        }
        OutPut("start timer:["+this->m_functionTag+"], interval:"+std::to_string(this->m_intervalMillionSecs.load())+
               ", repeated:"+(m_isRepeated.load()?"true":"false"));
        m_isStarted.store(true);
        m_isStopped.store(false);
        std::thread([this](){
            while (!this->m_isInTerminate.load())
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(this->m_intervalMillionSecs));
                if(this->m_isInTerminate.load()) {
                    OutPut("terminating, won't execute timer function:["+this->m_functionTag+"]");
                    return;
                }
                if(this->m_isStopped.load()){
                    OutPut("stopped, won't execute timer function:["+this->m_functionTag+"]");
                    return;
                }
                OutPut("will execute timer function:["+this->m_functionTag+"]");
                this->m_function();
                if(!this->m_isRepeated.load()){
                    OutPut("will execute timer function:["+this->m_functionTag+"]");
                    return;
                }
            }
        }).detach();
    }
    void stop()
    {
        if(!m_isStopped.load())
        {
            OutPut("stop timer function:["+this->m_functionTag+"]");
            m_isStopped.store(true);
        }
    }
public:
    std::atomic<unsigned long> m_intervalMillionSecs;
    std::atomic<bool> m_isRepeated;
    std::function<void(void)> m_function;
    std::string m_functionTag;
    std::atomic<bool> m_isStopped;
    std::atomic<bool> m_isStarted;
    std::atomic<bool> m_isInTerminate;
};

Timer::Timer(unsigned long intervalMillionSecs, std::function<void(void)> function, std::string funcTag, bool repeated)
    :_p(std::make_shared<TimerPrivate>(intervalMillionSecs,repeated,std::move(function),funcTag))
{

}

Timer::~Timer()
{
}

void Timer::start()
{
    _p->start();
}

void Timer::stop()
{
    _p->stop();
}