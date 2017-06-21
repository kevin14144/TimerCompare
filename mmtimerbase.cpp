#include "mmtimerbase.h"

MMTimerBase::MMTimerBase()
{

}

MMTimerBase::MMTimerBase(int Intervalms)
{
  m_Intervalms = Intervalms;
  m_replayDelay = Intervalms;
}

MMTimerBase::~MMTimerBase()
{
    Kill();
}

void MMTimerBase::SetIntervalms(int Intervalms)
{
    m_Intervalms = Intervalms;
}

void MMTimerBase::Start()
{
    record.clear();
    sum=0;
    count=0;

    timeGetDevCaps(&tc, sizeof(TIMECAPS));
    timeResolution = min(max(tc.wPeriodMin, 0), tc.wPeriodMax);
    timeBeginPeriod(1);//System Time Resolution
    // 取得目前 CPU frequency
    QueryPerformanceFrequency(&m_liPerfFreq);
    // 取得執行前時間
    QueryPerformanceCounter(&m_liPerfStart);

    //m_iStartTime = GetTickCount();
    TimerID = timeSetEvent(m_Intervalms, timeResolution ,(LPTIMECALLBACK)MMTimerBase::TimerFunction, 0,TIME_PERIODIC);//TIME_ONESHOT//TIME_PERIODIC
    myTimer = this;
}

void MMTimerBase::Kill()
{
    timeKillEvent(TimerID);
    timeEndPeriod(timeResolution);//Rest System Time Resolution
    TimerID=0;

    double avg =sum/count;
    qDebug()<<"Avg:"<<avg;
    qDebug()<<"Count:"<<count;
    double tempSum =0;
    for(std::list<double>::iterator it=record.begin(); it != record.end(); ++it)
    {
        tempSum += (*it - avg)*(*it - avg);
    }
    qDebug()<<"STD:"<< std::sqrt(tempSum/(count-1));


    double SumerrorAvg = 0;
    double maxError =-1;
    for(std::list<double>::iterator it=record.begin(); it != record.end(); ++it)
    {
        double error =std::abs(*it-(m_Intervalms/1000.0));
        if(maxError<error)
        {
            maxError = error;
        }
        SumerrorAvg += error;
    }

    SumerrorAvg/=count;
    qDebug()<<"Error Avg:"<< SumerrorAvg;
    qDebug()<<"Max Error:"<< maxError;
}

