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

short ReadMonth()
{
	short Number;

	cout << "\nPlease enter a Month ? ";
	cin >> Number;

	return Number;
}

short ReadDay()
{
	short Number;

	cout << "\nPlease enter a Day ? ";
	cin >> Number;

	return Number;
}

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a, y, m, d;

	a = (14 - Month) / 12;

	y = Year - a;

	m = Month + (12 * a) - 2;

	//Gregorian
	//0:Sun, 1:Mon, 2:Tue...etc

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

//My Way...

//string DayShortName(short Year, short Month, short Day) 
//{
//	string arrDaysName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
//	short DayOrder = DayOfWeekOrder(Year, Month, Day);
//	return arrDaysName[DayOrder];
//}

int main()
{
	short Year, Month, Day;

	Year = ReadYear();
	Month = ReadMonth();
	Day = ReadDay();


	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Year, Month, Day);
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Year, Month, Day)) << "\n\n";



	system("pause>0");
}
