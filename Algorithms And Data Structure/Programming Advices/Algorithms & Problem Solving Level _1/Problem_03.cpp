#include<iostream>
#include<string>//not use in this program but include.
using namespace std;

enum enNumberType { Even = 1, Odd };

int ReadNumber()
{
	int Number;
	cout << "Pleas entert Your Name?\n";
	cin >> Number;

	return Number;//return as outpot in variable
}

enNumberType checkNumberType(int Num)
{
	int Result = Num % 2;

	if (Result == 0)
	{
		return enNumberType::Even;
	}

	else
	{
		return enNumberType::Odd;
	}
}

void PrintNumberType(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
	{
		cout << "\n The Number is Even.\n";
	}
	else
	{
		cout << "\nThe Number is Odd.\n";
	}
}

int main()
{
	PrintNumberType(checkNumberType(ReadNumber()));

	return 0;
}