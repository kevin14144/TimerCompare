#include "standardwindowtimer.h"

STDTimerBase* STDTimerBase::myTimer;//

StandardWindowTimer::StandardWindowTimer():STDTimerBase()
{

}

StandardWindowTimer::StandardWindowTimer(int Intervalms):STDTimerBase(Intervalms)
{

}
StandardWindowTimer::~StandardWindowTimer()
{

}

void StandardWindowTimer::OnTimer()
{
    if(DoSomething != nullptr)
        DoSomething();//Function Pointer


}
