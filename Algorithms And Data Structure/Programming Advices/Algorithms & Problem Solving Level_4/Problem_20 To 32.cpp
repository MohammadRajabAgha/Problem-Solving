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

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

//01 
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

//02 
sDate IncreaseDateByXDays(sDate Date, short NumberOfDays)
{
    for (short i = 1; i <= NumberOfDays; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

//03 
sDate IncreaseDateByOneWeek(sDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

//04 
sDate IncreaseDateByXWeeks(sDate Date, short NumberOfWeeks)
{
    for (short i = 1; i <= NumberOfWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

//05 
sDate IncreaseDateByOneMonth(sDate Date)
{
  
    if (IsLastMonthInYear(Date.Month))
    {
        Date.Year++;
        Date.Month = 1;
    }

    else
        Date.Month++;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;
    

    return Date;
}

//06 
sDate IncreaseDateByXMonths(sDate Date, short NumberOfMonths)
{
    for (short i = 1; i <= NumberOfMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

//07-1
 
//sDate IncreaseDateByOneYear(sDate Date)
//{
//    return IncreaseDateByXMonths(Date, 12);
//}

//07-2
sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    

   short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;
    

    return Date;
}

//08 
sDate IncreaseDateByXYears(sDate Date, short NumberOfYears)
{
    for (short i = 1; i <= NumberOfYears; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

//09 
sDate IncreaseDateByXYearsFaster(sDate Date, short NumberOfYears)
{
    Date.Year += NumberOfYears;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

//10 
sDate IncreaseDateByOneDecade(sDate Date)
{
    for (short i = 1; i <= 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

//11 
sDate IncreaseDateByXDecades(sDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

//12 
sDate IncreaseDateByXDecadesFaster(sDate Date, short NumberOfDecades)
{
    Date.Year += (10 * NumberOfDecades);

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;


    return Date;
}

//13 
sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

//14 
sDate IncreaseDateByOneMillenium(sDate Date)
{
    Date.Year += 1000;

    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (NumberOfDaysInCurrentMonth < Date.Day)
        Date.Day = NumberOfDaysInCurrentMonth;

    return Date;
}

int main()
{
    sDate Date = ReadFullDate();

    cout << "\nDate Affter : \n";

    Date = IncreaseDateByOneDay(Date);
    cout << "\n01-Adding One Day is   : "; PrintFullDate(Date);

    Date = IncreaseDateByXDays(Date, 10);
    cout << "\n02-Adding 10 Days is   : "; PrintFullDate(Date);

    Date = IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding One Week is  : "; PrintFullDate(Date);

    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "\n04-Adding 10 Week is   : "; PrintFullDate(Date);

    Date = IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding One Month is : "; PrintFullDate(Date);

    Date = IncreaseDateByXMonths(Date, 5);
    cout << "\n06-Adding 5 Month is   : "; PrintFullDate(Date);

    Date = IncreaseDateByOneYear(Date);
    cout << "\n07-Adding One Year is  : "; PrintFullDate(Date);

    Date = IncreaseDateByXYears(Date, 10);
    cout << "\n08-Adding 10 Year is   : "; PrintFullDate(Date);

    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Adding 10 Year (Faster) is : "; PrintFullDate(Date);

    Date = IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding One Decade is : "; PrintFullDate(Date);

    Date = IncreaseDateByXDecades(Date, 10);
    cout << "\n11-Adding 10 Decades is : "; PrintFullDate(Date);

    Date = IncreaseDateByXDecadesFaster(Date, 10);
    cout << "\n12-Adding 10 Decades (Faster) is : "; PrintFullDate(Date);

    Date = IncreaseDateByOneCentury(Date);
    cout << "\n13-Adding One Century is : "; PrintFullDate(Date);

    Date = IncreaseDateByOneMillenium(Date);
    cout << "\n14-Adding One Millenium is : "; PrintFullDate(Date);

  
    system("pause>0");
}
