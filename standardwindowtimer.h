#ifndef STANDARDWINDOWTIMER_H
#define STANDARDWINDOWTIMER_H

#include "stdtimerbase.h"

class StandardWindowTimer:public STDTimerBase
{
public:
    StandardWindowTimer();
    StandardWindowTimer(int Intervalms);
    ~StandardWindowTimer();
private:
    void OnTimer() ;
};

#endif // STANDARDWINDOWTIMER_H
