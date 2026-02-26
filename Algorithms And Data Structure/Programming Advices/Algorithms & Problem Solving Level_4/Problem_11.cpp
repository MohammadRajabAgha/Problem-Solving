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

int main()
{

	short Day, Month, Year;

	Day = ReadDay();
	Month = ReadMonth();
	Year = ReadYear();

	short DaysOrderInAYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	cout << "\nNumber od Days From the Begining Of The Year is " << DaysOrderInAYear << endl;

	sDate Date;

	Date = GetDateFromDayOrderInYear(DaysOrderInAYear, Year);

	cout << "\nDate For [" << DaysOrderInAYear << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
}


//First Silution

//
//#include <iostream>
//
//using namespace std;
//
//short ReadYear()
//{
//	short Year;
//
//	cout << "\nPlease enter a Year ? ";
//	cin >> Year;
//
//	return Year;
//}
//
//short ReadMonth()
//{
//	short Month;
//
//	cout << "\nPlease entre a Month ? ";
//	cin >> Month;
//
//	return Month;
//}
//
//short ReadDay()
//{
//	short Day;
//
//	cout << "\nPlease entre a Day ? ";
//	cin >> Day;
//
//	return Day;
//}
//
//bool IsLeapYear(short Year)
//{
//	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
//}
//
//short NumberOfDaysInAMonth(short Month, short Year)
//{
//	if (Month < 1 || Month>12)
//		return 0;
//
//	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
//
//}
//
//short TotalDaysFromtheBeginingOfTheYear(short Day, short Month, short Year)
//{
//	short TotalDays = 0;
//
//	for (short i = 1; i <= Month - 1; i++)
//	{
//		TotalDays += NumberOfDaysInAMonth(i, Year);
//	}
//
//	TotalDays += Day;
//
//	return TotalDays;
//}
//
//void DateFromTotalDays(short TotalDays, short& Day, short& Month, short Year)
//{
//	short Counter = 1;
//
//	while (TotalDays > 28)
//	{
//		TotalDays -= NumberOfDaysInAMonth(Counter, Year);
//		++Counter;
//		++Month;
//	}
//
//	++Month;
//	Day = TotalDays;
//}
//
//int main()
//{
//
//	short Day, Month, Year;
//
//	Day = ReadDay();
//	Month = ReadMonth();
//	Year = ReadYear();
//
//	short TotalDays = TotalDaysFromtheBeginingOfTheYear(Day, Month, Year);
//
//	cout << "\nNumber od Days From the Begining Of The Year is " << TotalDays << endl;
//
//	Day = Month = 0;
//
//	DateFromTotalDays(TotalDays, Day, Month, Year);
//
//	cout << "Date For [" << TotalDays << "] is : ";
//	printf("%d/%d/%d", Day, Month, Year);
//
//	system("pause>0");
//}


//Second Silution
  
//#include <iostream>
//
//using namespace std;
//
//short ReadYear()
//{
//	short Year;
//
//	cout << "\nPlease enter a Year ? ";
//	cin >> Year;
//
//	return Year;
//}
//
//short ReadMonth()
//{
//	short Month;
//
//	cout << "\nPlease entre a Month ? ";
//	cin >> Month;
//
//	return Month;
//}
//
//short ReadDay()
//{
//	short Day;
//
//	cout << "\nPlease entre a Day ? ";
//	cin >> Day;
//
//	return Day;
//}
//
//bool IsLeapYear(short Year)
//{
//	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
//}
//
//short NumberOfDaysInAMonth(short Month, short Year)
//{
//	if (Month < 1 || Month>12)
//		return 0;
//
//	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//
//	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
//
//}
//
//short TotalDaysFromtheBeginingOfTheYear(short Day, short Month, short Year)
//{
//	short TotalDays = 0;
//
//	for (short i = 1; i <= Month - 1; i++)
//	{
//		TotalDays += NumberOfDaysInAMonth(i, Year);
//	}
//
//	TotalDays += Day;
//
//	return TotalDays;
//}
//
//void GetDateFromDayOrderInYear(short DaysOrderInAYear, short& Day, short& Month, short Year)
//{
//	short Counter = 1;
//
//	while (DaysOrderInAYear > 28)
//	{
//		DaysOrderInAYear -= NumberOfDaysInAMonth(Counter, Year);
//		++Counter;
//		++Month;
//	}
//
//	++Month;
//	Day = DaysOrderInAYear;
//}
//
//int main()
//{
//
//	short Day, Month, Year;
//
//	Day = ReadDay();
//	Month = ReadMonth();
//	Year = ReadYear();
//
//	short DaysOrderInAYear = TotalDaysFromtheBeginingOfTheYear(Day, Month, Year);
//
//	cout << "\nNumber od Days From the Begining Of The Year is " << DaysOrderInAYear << endl;
//
//	Day = Month = 0;
//
//	GetDateFromDayOrderInYear(DaysOrderInAYear, Day, Month, Year);
//
//	cout << "Date For [" << DaysOrderInAYear << "] is : ";
//	printf("%d/%d/%d", Day, Month, Year);
//
//	system("pause>0");
//}
//
