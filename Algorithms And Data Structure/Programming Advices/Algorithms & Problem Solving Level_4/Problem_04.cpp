#include <iostream>

using namespace std;

short ReadYear()
{
	short Number = 0;

	cout << "Plese Enter a Year to check ? ";
	cin >> Number;

	return Number;
}

bool IsLeapYear(short Year)
{
	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short  NumberOfHoursInAYear(short Year)
{
	return NumberOfDaysInAYear(Year) * 24;
}

int  NumberOfMinutesInAYear(short Year)
{
	return  NumberOfHoursInAYear(Year) * 60;
}

int  NumberOfSecondsInAYear(short Year)
{
	return NumberOfMinutesInAYear(Year) * 60;
}

int main()
{
	short Year = ReadYear();

	cout << "\nNumber Of Days    in Year [" << Year << "] is " << NumberOfDaysInAYear(Year);
	cout << "\nNumber Of Hours   in Year [" << Year << "] is " << NumberOfHoursInAYear(Year);
	cout << "\nNumber Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInAYear(Year);
	cout << "\nNumber Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInAYear(Year) << "\n\n";


	system("pause>0");
}


//My Solution...

//#include <iostream> 
//
//using namespace std;
//
//short ReadYear()
//{
//	short Number = 0; 
//	
//	cout << "Plese Enter a Year to check ? ";
//	cin >> Number; 
//	
//	return Number; 
//
//}
//
//bool IsLeapYear(short Year)
//{
//	return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0))); 
//}
//
//short NumberOfDaysInYear(short Year) 
//{
//	return IsLeapYear(Year) ? 366 : 365; } 
//
//short NumberOfHoursInYear(short Year)
//{
//	return NumberOfDaysInYear(Year) * 24; 
//}
//
//int NumberOfMinutesInYear(short Year) 
//{
//	return NumberOfDaysInYear(Year) * 24 * 60; 
//}
//
//int NumberOfSecondsInYear(short Year)
//{
//	return NumberOfDaysInYear(Year) * 24 * 60 * 60; 
//}
//
//int main()
//{
//	short Year = ReadYear(); 
//	
//	cout << "\nNumber Of Days in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
//	cout << "\nNumber Of Hours in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
//	cout << "\nNumber Of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
//	cout << "\nNumber Of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << "\n\n"; 
//	
//	system("pause>0");
//}