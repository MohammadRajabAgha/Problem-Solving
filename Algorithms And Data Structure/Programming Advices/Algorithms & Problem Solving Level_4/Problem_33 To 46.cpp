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

void PrintFullDate(sDate Date)
{
    cout << Date.Day << '/' << Date.Month << '/' << Date.Year;
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

bool IsFirstDayInMonth(short Day)
{
    return (Day == 1);
}

bool IsFirstMonthInYear(short Month)
{
    return (Month == 1);
}

sDate DecreaseDateByOneDay(sDate Date)
{
    if (IsFirstDayInMonth(Date.Day))
    {
        if (IsFirstMonthInYear(Date.Month))
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }

        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }

    else
    {
        Date.Day--;
    }

    return Date;
}

sDate DecreaseDateByXDays(sDate Date,short NumberOfDays)
{
    for (short i = 1; i <= NumberOfDays; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, short NumberOfWeeks)
{
    for (short i = 1; i <= NumberOfWeeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if (IsFirstMonthInYear(Date.Month))
    {
        Date.Year--;
        Date.Month = 12;
    }

    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

sDate DecreaseDateByXMonths(sDate Date,short NumberOfMonths)
{
    for (short i = 1; i <= NumberOfMonths; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

sDate DecreaseDateByXYears(sDate Date,short NumberOfYears)
{
    for (short i = 1; i <= NumberOfYears; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }


    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, short NumberOfYears)
{
    Date.Year -= NumberOfYears;


    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    for (short i = 1; i <= 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, short NumberOfDecades)
{
    Date.Year -= (NumberOfDecades * 10);

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

sDate DecreaseDateByoneCentury(sDate Date)
{
    Date.Year -= 100;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

int main()
{
    sDate Date = ReadFullDate();

    cout << "\nDate Affter : \n";

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01-Subtraction One Day is   : "; PrintFullDate(Date);

    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Subtraction 10 Days is   : "; PrintFullDate(Date);

    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Subtraction One Week is  : "; PrintFullDate(Date);

    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Subtraction 10 Week is   : "; PrintFullDate(Date);

    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Subtraction One Month is : "; PrintFullDate(Date);

    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Subtraction 5 Month is   : "; PrintFullDate(Date);

    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Subtraction One Year is  : "; PrintFullDate(Date);

    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08-Subtraction 10 Year is   : "; PrintFullDate(Date);

    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Adding 10 Year (Faster) is : "; PrintFullDate(Date);

    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Adding One Decade is : "; PrintFullDate(Date);

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "\n11-Adding 10 Decades is : "; PrintFullDate(Date);

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "\n12-Adding 10 Decades (Faster) is : "; PrintFullDate(Date);

    Date = DecreaseDateByoneCentury(Date);
    cout << "\n13-Adding One Century is : "; PrintFullDate(Date);

    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n14-Adding One Millenium is : "; PrintFullDate(Date);

    cout << endl;

    system("pause>0");
}
