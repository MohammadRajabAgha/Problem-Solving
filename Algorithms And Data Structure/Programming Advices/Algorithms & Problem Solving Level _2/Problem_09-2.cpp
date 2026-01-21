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

int CountDigitFrequency(int Number, short DigitToCheck)//important.
{
	int Remainder = 0;
	int FreqCount = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;//Extract the last digit of Number.
			Number = Number / 10;//Remove the last digit from Number.

			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
}

void PrintAllDigitFrequency(int Number)
{
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = 0;

		DigitFrequency = CountDigitFrequency(Number, i);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency " 
				 << DigitFrequency << " Time(s).\n"; 
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("Pleas enter The main Number?");
	
	PrintAllDigitFrequency(Number);


	return 0;
}