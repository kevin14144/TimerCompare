#ifndef STDTIMERBASE_H
#define STDTIMERBASE_H

#include <windows.h>
#include <map>
#include "qdebug.h"

class STDTimerBase
{
    typedef void (*CustomFunction)();
public:
    STDTimerBase();
    STDTimerBase(int Intervalms);
    virtual ~STDTimerBase();
    CustomFunction DoSomething = nullptr;
    void SetIntervalms(int Intervalms);
    void Start();
    void Kill();
protected:

    virtual void OnTimer()=0;

private:
    HWND m_nID;
    UINT_PTR TimerID;
    long m_Intervalms = 100;
    static STDTimerBase* myTimer;
    long m_replayDelay = 100;
    int m_iStartTime;
    LARGE_INTEGER m_liPerfFreq;
    LARGE_INTEGER m_liPerfStart;
    LARGE_INTEGER liPerfNow;
    double sum =0;
    double count =0;
    std::list<double> record;
    static void CALLBACK MyTimerProc( HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime )
    {
        // 取得執行後的時間
        QueryPerformanceCounter(&myTimer->liPerfNow);
        myTimer->OnTimer();

        //int m_replayDelay = iTime - myTimer->m_iStartTime;
        //std::thread th([](){myTimer->OnTimer();});
        //th.detach();

        double deley = ((double)myTimer->liPerfNow.QuadPart - myTimer->m_liPerfStart.QuadPart) / myTimer->m_liPerfFreq.QuadPart;

        qDebug()<<deley;
        myTimer->sum+=deley;
        myTimer->record.push_back(deley);
        myTimer->count++;

        if(myTimer->count>999)
        {
            myTimer->Kill();
        }
        // 取得目前 CPU frequency
        QueryPerformanceFrequency(&myTimer->m_liPerfFreq);
        // 取得執行前時間
        QueryPerformanceCounter(&myTimer->m_liPerfStart);
    }


};

#endif // STDTIMERBASE_H

