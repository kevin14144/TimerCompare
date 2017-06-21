#include "stdtimerbase.h"

STDTimerBase::STDTimerBase()
{

}

STDTimerBase::STDTimerBase(int Intervalms)
{
    m_Intervalms=Intervalms;

}

STDTimerBase::~STDTimerBase()
{
    Kill();
}

void STDTimerBase::SetIntervalms(int Intervalms)
{
    m_Intervalms = Intervalms;
}

void STDTimerBase::Start()
{
    sum=0;
    count =0;
    record.clear();
    // 取得目前 CPU frequency
    QueryPerformanceFrequency(&m_liPerfFreq);
    // 取得執行前時間
    QueryPerformanceCounter(&m_liPerfStart);
    TimerID = ::SetTimer(m_nID, 0, m_Intervalms, STDTimerBase::MyTimerProc);
    myTimer = this;
}

void STDTimerBase::Kill()
{
    ::KillTimer(m_nID,TimerID);
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
    double maxError =0;
    for(std::list<double>::iterator it=record.begin(); it != record.end(); ++it)
    {
        double error = std::abs(*it-(m_Intervalms/1000.0));
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


