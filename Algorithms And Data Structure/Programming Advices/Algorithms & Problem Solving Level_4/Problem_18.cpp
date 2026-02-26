#include <iostream>
#include<ctime>
#pragma warning(disable : 4996)
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
	int DiffDays = 0;

	while (IsDate1LessThanDate2(Date1, Date2))
	{
		DiffDays++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludingEndDay ? ++DiffDays : DiffDays;

}

sDate GetSystemDate()
{
	sDate CurrentDate;
	
	time_t T = time(0);
	tm* now = localtime(&T);

	CurrentDate.Year = now->tm_year + 1900;
	CurrentDate.Month = now->tm_mon + 1;
	CurrentDate.Day = now->tm_mday;
	
	return CurrentDate;
}


int main()
{
	cout << "Please enter Your Date Of Birth : \n";
	sDate BirthDate = ReadFullDate();
	
	sDate CurrentDate = GetSystemDate();

	cout << "\nYour Age is : " << GetDifferenceInDays(BirthDate, CurrentDate) << " Day(s).\n";
	cout << "\nYour Age (Encluding End Day) is: " << GetDifferenceInDays(BirthDate, CurrentDate, 1) << " Day(s).\n";

	
	
	
	system("pause>0");
}