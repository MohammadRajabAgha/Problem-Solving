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

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
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

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludingEndDay = false)
{
	int DiffDays = 0;
	short SwapFlagValue = 1;

	if (IsDate1AfterDate2(Date1, Date2))
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

//My Solution..

//int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludingEndDay = false)
//{
//	int DiffDays = 0;
//
//	if (!IsDate1LessThanDate2(Date1, Date2))
//	{
//		return (-1 * GetDifferenceInDays(Date2, Date1));
//	}
//
//	while (IsDate1LessThanDate2(Date1, Date2))
//	{
//		DiffDays++;
//		Date1 = IncreaseDateByOneDay(Date1);
//	}
//
//	return IncludingEndDay ? ++DiffDays : DiffDays;
//}

int main()
{
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrence is : " << GetDifferenceInDays(Date1, Date2) << " Day(s).";
	cout << "\nDiffrence (Including End Days) is : " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).\n";


	system("pause>0");
}



//        The Solution Using My Librarys

//#include <iostream>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//
//using namespace std;
//using sDate = MyLibraries::MyDateLibrary::sDate;
//
//int main()
//{
//	sDate Date1 = MyLibraries::MyDateLibrary::ReadFullDate();
//	sDate Date2 = MyLibraries::MyDateLibrary::ReadFullDate();
//
//	cout << "\nDiffrence is : " << MyLibraries::MyDateLibrary::GetDifferenceInDays(Date1, Date2);
//	cout << "\nDiffrence (Including End Day) is : " << MyLibraries::MyDateLibrary::GetDifferenceInDays(Date1, Date2, 1);
//	system("pause>0");
//}