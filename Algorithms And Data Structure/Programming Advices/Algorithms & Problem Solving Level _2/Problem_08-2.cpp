#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

int CountDigitFerquency(int Number,short DigitToCheck)//important.
{
	int Reminder = 0;
	int FreqCount = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;//Extract the last digit of Number.
		Number = Number / 10;//Remove the last digit from Number.
		if (DigitToCheck == Reminder)
		{
			FreqCount++;
		}
	}
	return FreqCount;
}

int main()
{
	int Number = ReadPositiveNumber("Pleas enter a Positive Number?");
	short DigitToCheck = ReadPositiveNumber("Pleas enetr The Digit?");

	cout << "\nDigit " << DigitToCheck << " Frequency is "
		<< CountDigitFerquency(Number, DigitToCheck) << " Time(s)\n";

	return 0;
}

