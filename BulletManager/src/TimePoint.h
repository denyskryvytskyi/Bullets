#ifndef __TIME_POINT_H__
#define __TIME_POINT_H__

#include <chrono>

typedef std::chrono::steady_clock::time_point Timepoint;

class TimePoint
{
	Timepoint mTimePoint;
public:
	bool operator==(const TimePoint& t) const;
	void SetCurrTime();
	float SecondsSince(const TimePoint& t) const;
};

float SecondsSince(const TimePoint& t);
TimePoint GetCurrTime();

#endif // !__TIME_POINT_H__
