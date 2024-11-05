#include "timeofday.h"
#include <iostream>

using std::cout;
using std::endl;

// constructor
TimeOfDay::TimeOfDay(int hour, int minute, int second)
{
    _hour = 0;
    _minute = 0;
    _second = 0;

    SetHour(hour);
    SetMinute(minute);
    SetSecond(second);
}

// mutator functions
void TimeOfDay::SetHour(int hour)
{
    if (hour >= 0 && hour <= 24)
        _hour = hour;
}

void TimeOfDay::SetMinute(int minute)
{
    if (minute >= 0 && minute <= 59)
        _minute = minute;
}
void TimeOfDay::SetSecond(int second)
{
    if (second >= 0 && second <= 59)
        _second = second;
}

// accessor functions
int TimeOfDay::GetHour() const
{
    return _hour;
}

int TimeOfDay::GetMinute() const
{
    return _minute;
}

int TimeOfDay::GetSecond() const
{
    return _second;
}

void TimeOfDay::Print(bool military, bool seconds) const
{
   int hour;
   string am_pm = "";
   if (military)
   {
        hour = _hour;
   }
   else
   {
        TimeInfo time_info = _get_time_info(_hour);
        hour = time_info.hour;
        am_pm = time_info.am_pm;
   }

   if (hour <= 9)
        cout << "0";
    
    cout << hour << ":";

    if (_minute <= 9)
        cout << "0";
    
    cout << _minute;

    if (seconds)
    {
        cout << ":";
        _second <= 9 ? cout << "0" << _second : cout << _second;
    }

    if (!military)
        cout << " " << am_pm;
    
    cout << endl;
}

TimeInfo TimeOfDay::_get_time_info(int hour) const
{
    TimeInfo time_info;
    if (hour == 0)
    {
        time_info.am_pm = "a.m.";
        time_info.hour = 12;
    }
    else if (hour > 12)
    {
        time_info.hour = _hour - 12;
        time_info.am_pm = "p.m.";
    }
    else
    {
        time_info.hour = _hour;
        time_info.am_pm = "a.m.";
    }

    return time_info;
}

bool TimeOfDay::operator<(const TimeOfDay &right) const
{
    int seconds_left = (_hour * 60 * 60) + (_minute * 60) + _second;
    int seconds_right = (right.GetHour() * 60 * 60) + (right.GetMinute() * 60) + right.GetSecond();
    return seconds_left < seconds_right;
}

bool TimeOfDay::operator>(const TimeOfDay &right) const
{
    int seconds_left = (_hour * 60 * 60) + (_minute * 60) + _second;
    int seconds_right = (right.GetHour() * 60 * 60) + (right.GetMinute() * 60) + right.GetSecond();
    return seconds_left > seconds_right;

}