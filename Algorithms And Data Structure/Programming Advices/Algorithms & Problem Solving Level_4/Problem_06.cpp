#include <iostream>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"

using namespace std;

short ReadYear()
{
	short Number;

	cout << "\nPlease enter a year to check ? ";
	cin >> Number;

	return Number;
}

short ReadMonth()
{
	short Number;

	cout << "\nPlease enter a Month to check ? ";
	cin >> Number;

	return Number;
}

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	// My Way...

	/*if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) return 31; if (Month != 2) return 30;

	return  (IsLeapYear(Year) && Month == 2) ? 29 : 28;*/

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

int main()
{
	short Year, Month;

	Year = ReadYear();
	Month = ReadMonth();

	cout << "\nNumber Of Days    in Month [" << Month << "] is "
		<< NumberOfDaysInAMonth(Year, Month);


	system("pause>0");
}
