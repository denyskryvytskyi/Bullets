#include "TimePoint.h"

void TimePoint::SetCurrTime()
{
    mTimePoint = std::chrono::steady_clock::now();
}

float TimePoint::SecondsSince(const TimePoint& t) const
{
    return 1.f + std::chrono::duration_cast<std::chrono::nanoseconds>(mTimePoint - t.mTimePoint).count() / (1000 * 1000 * 1000);
}

TimePoint GetCurrTime()
{
    TimePoint tp;
    tp.SetCurrTime();
    return tp;
}

float SecondsSince(const TimePoint& t)
{
    TimePoint now;
    now.SetCurrTime();
    return now.SecondsSince(t);
}