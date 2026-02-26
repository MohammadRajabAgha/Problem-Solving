#include <iostream>
#include<ctime>

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
    short Day;
    short Month;
    short Year;
};

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
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

short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
    short DaysCount = 0;

    while (IsDate1LessThanDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DaysCount;
}

sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
{
    short WeekEndCount = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
   
    //Unimportant

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    for (short i = 1; i <= VacationDays + WeekEndCount; i++)
    {
        if (IsWeekEnd(DateFrom))
            WeekEndCount++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //in case the return date is week end keep adding one day util you reach business day.
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}

int main()
{
    cout << "Vacation Starts : ";
    sDate DateFrom = ReadFullDate();

    short VacationDays = 0;
    cout << "\n\nPlease enter Vacation Days ? ";
    cin >> VacationDays;
    
    sDate DateTo = CalculateVacationReturnDate(DateFrom, VacationDays);
    cout << "\n\nReturn Date : " << DayShortName(DayOfWeekOrder(DateTo)) << ", "; PrintFullDate(DateTo);

    system("pause>0");
}

