#ifndef MMTIMERBASE_H
#define MMTIMERBASE_H

#include <qdebug.h>
#include <windows.h>
#include <Mmsystem.h>
#include <thread>
#include <list>
#include <math.h>


class MMTimerBase
{

    typedef void (*CustomFunction)();

public:
    MMTimerBase();
    MMTimerBase(int Intervalms);
    virtual ~MMTimerBase();
    CustomFunction DoSomething = nullptr;
    void SetIntervalms(int Intervalms);
    void Start();
    void Kill();



protected:

    virtual void OnTimer()=0;

private:
    MMRESULT TimerID;
    TIMECAPS tc;
    int  timeResolution = 10;
    long m_Intervalms = 100;
    long m_replayDelay = 100;
    int m_iStartTime;
    LARGE_INTEGER m_liPerfFreq;
    LARGE_INTEGER m_liPerfStart;
    LARGE_INTEGER liPerfNow;
    static MMTimerBase* myTimer;
    double sum =0;
    double count =0;
    double Std=0;
    std::list<double> record;

    static void CALLBACK TimerFunction(UINT wTimerID, UINT msg,DWORD dwUser, DWORD dw1, DWORD dw2)
    {
        // 取得執行後的時間
        QueryPerformanceCounter(&myTimer->liPerfNow);
        //int iTime = GetTickCount();
        SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
        myTimer->OnTimer();

        //int m_replayDelay = iTime - myTimer->m_iStartTime;
        //        std::thread th([](){myTimer->OnTimer();});
        //        th.detach();

        double deley = ((double)myTimer->liPerfNow.QuadPart - myTimer->m_liPerfStart.QuadPart ) / myTimer->m_liPerfFreq.QuadPart;
        qDebug()<<deley;
        myTimer->record.push_back(deley);
        myTimer->sum += deley;
        myTimer->count ++;

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

#endif // MMTIMERBASE_H
