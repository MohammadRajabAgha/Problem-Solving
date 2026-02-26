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

struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
};

sPeriod ReadPeriod()
{
    sPeriod Period;

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

bool IsOverLapPeriods(sPeriod Period1, sPeriod Period2)
{
    if (CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::After
        ||
        CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::Before)
        return false;

    return true;

}


//bool IsOverLapPeriods(sPeriod Period1, sPeriod Period2)
//{
//    if (CompareDates(Period1.StartDate, Period2.StartDate) == enDateCompare::After && CompareDates(Period1.EndDate, Period2.EndDate) == enDateCompare::After)
//    {
//        return (!IsDate1BeforeDate2(Period2.EndDate, Period1.StartDate));
//    }
//
//    return (!IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate));
//
//    return false;
//}

int main()
{
    cout << "\nEnter Period 1 : ";
    sPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2 : ";
    sPeriod Period2 = ReadPeriod();

    if (IsOverLapPeriods(Period1, Period2))
    {
        cout << "\nYes, Is OverLap Period.\n";
    }
    else
    {
        cout << "\nNo, Is NOT OverLap Period.\n";
    }
}

