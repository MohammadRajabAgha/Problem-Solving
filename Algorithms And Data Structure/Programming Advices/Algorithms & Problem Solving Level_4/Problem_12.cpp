#include <iostream>

using namespace std;

short ReadYear()
{
	short Year;

	cout << "\nPlease enter a Year ? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month;

	cout << "\nPlease entre a Month ? ";
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

short ReadNumber()
{
	short NumberOfDays;

	cout << "\nHow Many days to add ? ";
	cin >> NumberOfDays;

	return NumberOfDays;
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

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate GetDateFromDayOrderInYear(short DayOrderInAYear, short Year)
{
	short RemaningDays = DayOrderInAYear;
	short MonthDays;

	sDate Date;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
		if (RemaningDays > MonthDays)
		{
			RemaningDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemaningDays;
			break;
		}

	}

	return Date;
}

sDate DateAddDays(short NumberOfDaysToAdd, sDate Date)
{

	short RemaningDays = NumberOfDaysToAdd + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDay = 0;

	Date.Month = 1;

	while (true)
	{
		MonthDay = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemaningDays > MonthDay)
		{
			RemaningDays -= MonthDay;

			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}

		else
		{
			Date.Day = RemaningDays;
			break;
		}

	}

	return Date;

}

//My Salution By Recursion Function

//sDate DateAddDays(short NumberOfDaysToAdd, sDate Date)
//{
//
//	short RemaningdaysToAdd = NumberOfDaysToAdd;
//
//	short DayOrderbeforAdding = NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
//
//	short DayOrderAfterAdding = DayOrderbeforAdding + RemaningdaysToAdd;
//
//	if (IsLeapYear(Date.Year))
//	{
//		if (DayOrderAfterAdding <= 366)
//		{
//			return GetDateFromDayOrderInYear(DayOrderAfterAdding, Date.Year);
//		}
//
//		else
//		{
//			RemaningdaysToAdd -= (367 - DayOrderbeforAdding);// We use The Numbe 367 
//			//Because The have one number in (1/1)
//
//			Date.Day = 1;
//			Date.Month = 1;
//			Date.Year += 1;
//
//			return AddNumberOfDaysToDate(RemaningdaysToAdd, Date);
//		}
//
//	}
//	
//	if (!IsLeapYear(Date.Year))
//	{
//		if (DayOrderAfterAdding <= 365)
//		{
//			return GetDateFromDayOrderInYear(DayOrderAfterAdding, Date.Year);
//		}
//
//		else
//		{
//			RemaningdaysToAdd -= (366 - DayOrderbeforAdding);// We use The Numbe 366 
//			//Because The have one number in (1/1)
//
//			Date.Day = 1;
//			Date.Month = 1;
//			Date.Year += 1;
//
//			return AddNumberOfDaysToDate(RemaningdaysToAdd, Date);
//		}
//
//	}
//}

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	short NumberOfDaysToAdd = ReadNumber();


	Date = DateAddDays(NumberOfDaysToAdd, Date);

	cout << "\nDate After Adding [" << NumberOfDaysToAdd << "] days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
}