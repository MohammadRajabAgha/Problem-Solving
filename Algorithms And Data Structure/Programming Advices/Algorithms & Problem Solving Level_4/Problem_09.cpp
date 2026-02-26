#include <iostream>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
#include<cstdio>
using namespace std;

short ReadYear()
{
	short Number;

	cout << "\nPlease enter a year ? ";
	cin >> Number;

	return Number;
}

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
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

string MonthShortName(short Month)
{
	string arrMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonthNames[Month - 1];
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

void PrintMonthCalendar(short Month, short Year)
{
	int NumberOfDays;

	// Index of the day from 0 to 6
	int current = DayOfWeekOrder(1, Month, Year);

	NumberOfDays = NumberOfDaysInAMonth(Month, Year);

	// Print the current month name
	printf("\n _______________%s_______________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces (4 spaces per day)
	int i;
	for (i = 0; i < current; i++)
		printf("     ");  // 5 مسافات (لكن المسافة الأولى من %5d)

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);  // %5d = 4 مسافات + الرقم

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n _________________________________\n");
}

void PrintYearCalendar(int Year)
{
	printf("\n _________________________________\n\n");
	printf("\t  Calendar - %d", Year);
	printf("\n _________________________________\n");

	for (short i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);
	}

}

int main()
{
	short Year, Month, Day;

	Year = ReadYear();

	PrintYearCalendar(Year);

	system("pause>0");
}
