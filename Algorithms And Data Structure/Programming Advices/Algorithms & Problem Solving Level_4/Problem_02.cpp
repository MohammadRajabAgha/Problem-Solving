#include <iostream>

using namespace std;

//Solution 1...

//bool IsLeapYear(short Year) 
//{
//	if (Year % 400 == 0)
//	{
//		return true; 
//	}
//	
//	if ((Year % 4 == 0) && (Year % 100 != 0)) 
//	{
//		return true; 
//	}
//	
//	return false; 
//}

//Solution 2...

//bool IsLeapYear(short Year)
//{
//	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
//}

bool IsLeapYear(short Year)
{
	if (Year % 400 == 0)
	{
		return true;
	}


	else if (Year % 100 == 0)
	{
		return false;
	}

	else if (Year % 4 == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
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