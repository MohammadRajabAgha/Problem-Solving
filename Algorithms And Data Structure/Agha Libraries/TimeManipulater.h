#pragma once

#pragma warning(disable : 4996)

#include<iostream>

using namespace std;

namespace TimeManipulater
{
    string LocalTime()
    {
        //"Don't Forget This Code"
//#pragma warning(disable : 4996)


        time_t t = time(0); // get time now

        char* dt = ctime(&t);   // convert to string form  

        return dt;
    }

    string GMT_Time()
    {
        //"Don't Forget This Code"
//#pragma warning(disable : 4996)

        time_t t = time(0); // get time now

        // converting now to tm struct for UTC date/time
        tm* gmtm = gmtime(&t);

        char* dt = asctime(gmtm);//converting time struct to String


        return dt;
    }

    bool IsLeapYear(short Year)
    {
        return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
    }

    short NumberOfDaysInAYear(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }

    short  NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    int  NumberOfMinutesInAYear(short Year)
    {
        return  NumberOfHoursInAYear(Year) * 60;
    }

    int  NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month>12)
            return 0;

        short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

    }

    short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Year, Month) * 24;
    }

    int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Year, Month) * 60;
    }

    int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Year, Month) * 60;
    }

    short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m, d;

        a = (14 - Month) / 12;

        y = Year - a;

        m = Month + (12 * a) - 2;

        //Gregorian
        //0:Sun, 1:Mon, 2:Tue...etc

        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

        return arrDayNames[DayOfWeekOrder];
    }

}