#include<iostream>
#include<string>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float HourToDays(float NumberOfHours)
{
	return NumberOfHours / 24;
}

float HourToWeeks(float NumberOfHours)
{
	return NumberOfHours / 7 / 24;
}

//float DaysToWeeks(float NumberOfDays)
//{
//	return NumberOfDays / 7;
//}

int main()
{
	float NumberOfHours = ReadPositiveNumber("Pleas Enter a Number Of Hours?");
	float NumberOfDays = HourToDays(NumberOfHours);
	float NumberOfWeeks = HourToWeeks(NumberOfHours);
	//float NUmberOfWeeks=DaysToWeeks(NumberOfDays);

	cout << "\nTotal Hours= " << NumberOfHours << " Hours \n";
	cout << "Total Days= " << NumberOfDays << " Days \n";
	cout << "Total Weeks= " << NumberOfWeeks << " Weeks " << endl;
	

	return 0;
}