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

//My Solution...

//sDate IncreaseDateByOneDay(sDate Date)
//{
//	(IsLastDayInMonth(Date) ?
//		(
//			(IsLastMonthInYear(Date.Month) ? (Date.Month = Date.Day = 1, Date.Year++) : Date.Month++, Date.Day = 1)
//		)
//		: Date.Day++
//	);
//	
//	return Date;
//}

int main()
{
	sDate Date = ReadFullDate();

	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate After Adding One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
}