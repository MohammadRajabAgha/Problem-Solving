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

bool IsDateInPeriod(stPeriod Period, stDate Date)
{
    return !(CompareDates(Period.StartDate, Date) == enDateCompare::After 
        ||
        CompareDates(Period.EndDate, Date) == enDateCompare::Before);
}

int main()
{
    cout << "\nEnter Period 1 : ";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Date To Check : \n";
    stDate Date = ReadFullDate();

    if (IsDateInPeriod(Period1, Date))
    {
        cout << "\nYes, Date is Within Period.\n";
    }
    else
    {
        cout << "\nNo, Date is NOT Within Period.\n";
    }

    system("pause>0");
    return 0;
}

