#include "multmediatimer.h"

MMTimerBase* MMTimerBase::myTimer;

MultMediaTimer::MultMediaTimer():MMTimerBase()
{

}

MultMediaTimer::MultMediaTimer(int Intervalms):MMTimerBase(Intervalms)
{

}

MultMediaTimer::~MultMediaTimer()
{

}

void MultMediaTimer::OnTimer()
{
    if(DoSomething != nullptr)
        DoSomething();//Function Pointer

}


