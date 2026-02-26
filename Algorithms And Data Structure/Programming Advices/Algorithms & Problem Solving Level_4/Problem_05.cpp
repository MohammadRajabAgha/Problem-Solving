#include <iostream>

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

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (int i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}

int main()
{
	short Year, Month;

	Year = ReadYear();
	Month = ReadMonth();

	cout << "\nNumber Of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Year, Month);
	cout << "\nNumber Of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Year, Month);
	cout << "\nNumber Of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Year, Month);
	cout << "\nNumber Of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Year, Month) << endl;


	system("pause>0");
}
