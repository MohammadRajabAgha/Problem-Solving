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

/*
bool IsValidDay(stDate Date)
{
    return (1 <= Date.Day && Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsValidMonth(short Month)
{
    return (1 <= Month && Month <= 12);
}

bool IsValidDate(stDate Date)
{
    return (IsValidMonth(Date.Month) && IsValidDay(Date));
}
*/

bool IsValidDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day>31)
        return false;

    if (Date.Month < 1 || Date.Month>12)
        return false;

    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
       
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }

    short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        return false;

    return true;

}

int main()
{
    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
    {
        cout << "\nYes, Is Valid Date.\n";
    }
    else
    {
        cout << "\nNo, Is NOT a Valid Date.\n";
    }

    system("pause>0");
    return 0;
}

