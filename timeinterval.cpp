#include <iostream>
using std::cout;
using std::endl;
#include "timeinterval.h"

TimeInterval::TimeInterval(const TimeOfDay &start_time, const TimeOfDay &end_time)
{
    if (start_time > end_time)
    {
        _start_time = start_time;
        _end_time = start_time;
    }
    else
    {
        _start_time = start_time;
        _end_time = end_time;
    }
}
TimeInterval::TimeInterval(const TimeOfDay &start_time, int length, string units)
{
    _start_time = start_time;
    SetEndTime(length, units);
    if (_end_time.GetHour() == 0 && _end_time.GetMinute() == 0 && _end_time.GetSecond() == 0)
    {
        _end_time = start_time;
    }
}

// accessor functions
TimeOfDay TimeInterval::GetStartTime() const
{
    return _start_time;
}

TimeOfDay TimeInterval::GetEndTime() const
{
    return _end_time;
}

// mutator functions
void TimeInterval::SetStartTime(const TimeOfDay &start_time)
{
    if (start_time > _end_time)
        return;
    
    _start_time = start_time;
}
void TimeInterval::SetEndTime(const TimeOfDay &end_time)
{
    if (end_time < _start_time)
        return;
    _end_time = end_time;
}
void TimeInterval::SetEndTime(int length, string units)
{
    int end_hours = _start_time.GetHour();
    int end_minutes = _start_time.GetMinute();
    int end_seconds = _start_time.GetSecond();
    TimeOfDay end_time;
    if (units == "hours")
    {
        end_hours += length;
    }
    else if (units == "minutes")
    {
        int new_minutes = end_minutes + length;
        end_minutes = new_minutes % 60;
        end_hours += new_minutes / 60;

    }
    else if (units == "seconds")
    {
        int new_seconds = end_seconds + length;
        end_seconds = new_seconds % 60;
        end_minutes += new_seconds / 60;
    }
    else
        return;
    
    end_time = TimeOfDay(end_hours, end_minutes, end_seconds);
    if (end_hours <= 24 && end_minutes <= 59 && end_seconds <= 59 && _start_time < end_time)
        _end_time = end_time;
    
}
void TimeInterval::Print(bool military, bool show_seconds) const
{
    cout << "Start time: ";
    _start_time.Print(military, show_seconds);
    cout << "End time: ";
    _end_time.Print(military, show_seconds);
}
