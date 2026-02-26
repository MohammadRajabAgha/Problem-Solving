#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
}

short ReadYear()
{
	short Number = 0;

	cout << "Plese Enter a Year ? ";
	cin >> Number;

	return Number;
}

int main()
{
	short Year = ReadYear();

	if (IsLeapYear(Year))
	{
		cout << "\nYes, Year [" << Year << "] is a Leap Year.\n";
	}
	else
	{
		cout << "\nNo, Year [" << Year << "] is NOT a Leap Year.\n";
	}

	system("pause>0");
}