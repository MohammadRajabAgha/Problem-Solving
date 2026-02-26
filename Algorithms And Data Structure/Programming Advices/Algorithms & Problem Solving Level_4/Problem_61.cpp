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

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{

    return (Date1.Year == Date2.Year) ?
        (
            (Date1.Month == Date2.Month) ? Date1.Day == Date2.Day : false
            )
        : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return(!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
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

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
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

void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludingEndDay = false)
{
    int DiffDays = 0;
    short SwapFlagValue = 1;

    if (IsDate1AfterDate2(Date1,Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = IncreaseDateByOneDay(Date1);
        DiffDays++;
    }

    return IncludingEndDay ? ++DiffDays * SwapFlagValue : DiffDays * SwapFlagValue;

}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
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

bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After
        ||
        CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before)
        return false;

    return true;

}

int PeriodLengthInDays(stPeriod Period, bool IncludingEndDay = false)
{
    return(GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludingEndDay));
}

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
    return !(CompareDates(Period.StartDate, Date) == enDateCompare::After
        ||
        CompareDates(Period.EndDate, Date) == enDateCompare::Before);
}

//int CountOverLapDays(stPeriod Period1, stPeriod Period2)
//{
//    short Period1Length = PeriodLengthInDays(Period1, true);
//    short Period2Length = PeriodLengthInDays(Period2, true);
//    int OverLapDays = 0;
//
//    if (!IsOverLapPeriods(Period1, Period2))
//        return 0;
//
//    if (Period1Length < Period2Length)
//    {
//        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
//        {
//            if (IsDateInPeriod(Period2, Period1.StartDate))
//                OverLapDays++;
//
//            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
//        }
//    }
//
//    else
//    {
//        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
//        {
//            if (IsDateInPeriod(Period1, Period2.StartDate))
//                OverLapDays++;
//
//            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
//        }
//    }
//
//    return OverLapDays;
//}

//My Solution 

int CountOverLapDays(stPeriod Period1, stPeriod Period2)
{
    //This fuction return Number Of Days Without Encuding End Days.

    stPeriod OverLapPeriod;
    int Days = 0;

    if (!IsOverLapPeriods(Period1, Period2))
        return -1;

    (CompareDates(Period1.StartDate, Period2.StartDate) == enDateCompare::After) ?
        (OverLapPeriod.StartDate = Period1.StartDate) 
            :
        (OverLapPeriod.StartDate = Period2.StartDate);


    (CompareDates(Period1.EndDate, Period2.EndDate) == enDateCompare::Before) ?
        (OverLapPeriod.EndDate = Period1.EndDate)
            :
        (OverLapPeriod.EndDate = Period2.EndDate);


    return GetDifferenceInDays(OverLapPeriod.StartDate, OverLapPeriod.EndDate);
}

int main()
{
    cout << "\nEnter Period 1 : ";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2 : ";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverLap Days Count is : " << CountOverLapDays(Period1, Period2) << endl;

    system("pause>0");
    return 0;
}

