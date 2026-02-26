#include <iostream>

using namespace std;


short ReadYear()
{
    short Year;

    cout << "Please enter a Year ? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month;

    cout << "Please entre a Month ? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\nPlease entre a Day ? ";
    cin >> Day;

    return Day;
}

struct sDate
{
    short Year;
    short Month;
    short Day;
};

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date  : \n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date  : \n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
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

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{

    return (Date1.Year == Date2.Year) ?
        (
            (Date1.Month == Date2.Month) ? Date1.Day == Date2.Day : false
            )
        : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;

    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    /*if (IsDate1AfterDate2(Date1, Date2))
        return enDateCompare::After;*/

        //This is Faster
    return enDateCompare::After;
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

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        DiffDays++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludingEndDay ? ++DiffDays * SwapFlagValue : DiffDays * SwapFlagValue;

}

int PeriodLengthInDays(stPeriod Period, bool IncludingEndDay = false)
{
    return(GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludingEndDay));
}
 
int main()
{
    cout << "\nEnter Period 1 : ";
    stPeriod Period1 = ReadPeriod();

    cout << "\nPeriod Length is : " << PeriodLengthInDays(Period1);
    cout << "\nPeriod Length is (Encluding End Days) : " << PeriodLengthInDays(Period1, true);

}

