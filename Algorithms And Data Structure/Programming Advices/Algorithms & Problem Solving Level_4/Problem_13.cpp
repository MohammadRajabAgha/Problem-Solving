#include <iostream>

using namespace std;

short ReadYear()
{
	short Year;

	cout << "Please enter a Year ? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month;

	cout << "Please entre a Month ? ";
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

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{

	return (Date1.Year < Date2.Year) ? true :
		(
			(Date1.Year == Date2.Year) ?
			(
				(Date1.Month < Date2.Month) ? true :
				(
					(Date1.Month == Date2.Month) ?
					Date1.Day < Date2.Day :
					false
				)
			) :
			false
		); 
}

int main()
{
	sDate Date1 = ReadFullDate();

	sDate Date2 = ReadFullDate();

	if (IsDate1LessThanDate2(Date1, Date2))
	{
		cout << "\n\nYes, Date 1 Less Than Date 2.\n";
	}

	else
	{
		cout << "\n\nNo, Date 1 NOT Less Than Date 2.\n";
	}

	system("pause>0");
}