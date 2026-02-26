#include <iostream>
#include<ctime>

using namespace std;

#pragma warning(disable : 4996)

struct sDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLeapYear(short Year)
{
    return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{

    return (Date1.Year < Date2.Year) ? true :
        (
            (Date1.Year == Date2.Year) ?
            (
                (Date1.Month < Date2.Month) ? true :
                (
                    (Date1.Month == Date2.Month) ?
                    Date1.Day < Date2.Day :
                    false
                    )
                ) :
            false
            );
}

void SwapDates(sDate& Date1, sDate& Date2)
{
    sDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }

        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }

    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
    int DiffDays = 0;
    short SwapFlagValue = 1;

    if (!IsDate1LessThanDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1LessThanDate2(Date1, Date2))
    {
        DiffDays++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludingEndDay ? ++DiffDays * SwapFlagValue : DiffDays * SwapFlagValue;

}

void PrintFullDate(sDate Date)
{
    cout << Date.Day << '/' << Date.Month << '/' << Date.Year;
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

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

    return arrDayNames[DayOfWeekOrder];
}

sDate GetSystemDate()
{
    sDate CurrentDate;

    time_t T = time(0);
    tm* now = localtime(&T);

    CurrentDate.Year = now->tm_year + 1900;
    CurrentDate.Month = now->tm_mon + 1;
    CurrentDate.Day = now->tm_mday;

    return CurrentDate;
}

bool IsEndOfWeek(sDate Date)
{
    return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(sDate Date)
{
    //Weekends are Fri and Sat

    short DateIndex = DayOfWeekOrder(Date);

    return (DateIndex == 5 || DateIndex == 6);
}

bool IsBusinessDay(sDate Date)
{
    //return(DayOfWeekOrder != 5 || DayOfWeekOrder != 6);
    return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(sDate Date)
{
    return(6 - DayOfWeekOrder(Date));
}

short DaysUntilTheEndOfMonth(sDate Date)
{
    sDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date)
{
    sDate EndOfYearDate;

    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDifferenceInDays(Date, EndOfYearDate, true);
}

int main()
{
    sDate Date = GetSystemDate();

    short OrderOfDayInWeek = DayOfWeekOrder(Date);

    cout << "Today is " << DayShortName(OrderOfDayInWeek) << ", "; PrintFullDate(Date);

    cout << "\n\nIt is The End Of Week ? \n";
    if (IsEndOfWeek(Date))
    {
        cout << "Yes it is Saturday, it is End Of Week.";
    }
    else
    {
        cout << "No, it is NOT End Of Week.";
    }
   
    cout << "\n\nIt is WeekEnd ? \n";
    if (IsWeekEnd(Date))
    {
        cout << "Yes, it is a WeekEnd.";
    }
    else
    {
        cout << "No Today is " << DayShortName(OrderOfDayInWeek) << ", NOT a WeekEnd.";
    }

    cout << "\n\nIt is Business Day ? \n";
    if (IsBusinessDay(Date))
    {
        cout << "Yes, it is a Business Day.";
    }
    else
    {
        cout << "No, it is NOT a Business Day.";
    }

    cout << "\n";

    cout << "\nDays Until The End Of Week  : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";
    cout << "\nDays Until The End Of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
    cout << "\nDays Until The End Of Year  : " << DaysUntilTheEndOfYear(Date) << " Day(s).";

    system("pause>0");
}

