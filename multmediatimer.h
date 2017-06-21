#ifndef MULTMEDIATIMER_H
#define MULTMEDIATIMER_H

#include "mmtimerbase.h"

class MultMediaTimer : public MMTimerBase
{
public:
    MultMediaTimer();
    MultMediaTimer(int Intervalms);
    ~MultMediaTimer();
private:
    void OnTimer() ;
};

#endif // MULTMEDIATIMER_H
