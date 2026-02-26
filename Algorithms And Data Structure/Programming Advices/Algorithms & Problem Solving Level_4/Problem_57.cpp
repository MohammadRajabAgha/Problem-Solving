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

enum enDateCompare { Before = -1, Equal, After };

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
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

//My Solution

//enDateCompare CompareDates(sDate Date1, sDate Date2)
//{
//    return (IsDate1BeforeDate2(Date1, Date2) ? enDateCompare::Before : (IsDate1EqualDate2(Date1, Date2) ? enDateCompare::Equal : enDateCompare::After));
//}

int main()
{
    cout << "\nEnter Date1 : ";
    sDate Date1 = ReadFullDate();

    cout << "\nEnter Date2 : ";
    sDate Date2 = ReadFullDate();

    cout << "\n\nCompare Result = " << CompareDates(Date1, Date2) << endl;

    system("pause>0");
    return 0;
}
