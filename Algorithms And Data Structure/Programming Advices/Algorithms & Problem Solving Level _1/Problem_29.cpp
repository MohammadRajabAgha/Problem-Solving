#include<iostream>
using namespace std;

enum enCheckOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Num;
	cout << "Pleas Enter a Number?\n";
	cin >> Num;

	return Num;
}

enCheckOddOrEven CheckOddOrEven(int Num)
{
	if (Num % 2 == 0)
		return enCheckOddOrEven::Even;
	else
		return enCheckOddOrEven::Odd;
}

int SumEvenNumberFrom1ToN_UsingFor(int Num)
{
	cout << "****************************\n";
	cout << "For Loop\n";
	int Sum = 0;

	for (int Counter = 0; Counter <= Num; Counter = Counter++)
	{
		if (CheckOddOrEven(Counter) == enCheckOddOrEven::Even)
		{
			Sum += Counter;
		}

	}
	return Sum;
}

int SumEvenNumberFrom1ToN_UsingWhile(int Num)
{
	cout << "****************************\n";
	cout << "While Loop\n";
	int Sum = 0;
	int Counter = 0;

	while (Counter <= Num)
	{
		if (CheckOddOrEven(Counter) == enCheckOddOrEven::Even)
		{
			Sum += Counter;

		}
		Counter++;
	}

	return Sum;
}

int SumEvenNumberFrom1ToN_UsingDoWhile(int Num)
{
	cout << "****************************\n";
	cout << "Do...While\n";
	int Sum = 0;
	int Counter = 0;
	do
	{
		if (CheckOddOrEven(Counter) == enCheckOddOrEven::Even)
		{
			Sum += Counter;

		}
		Counter++;

	} while (Counter <= Num);

	return Sum;
}

void PrintSumOddNumberFrom1ToN(int Sum)
{
	cout << "The Sum is " << Sum << endl;
}

int main()
{
	int N = ReadNumber();

	PrintSumOddNumberFrom1ToN(SumEvenNumberFrom1ToN_UsingFor(N));
	PrintSumOddNumberFrom1ToN(SumEvenNumberFrom1ToN_UsingWhile(N));
	PrintSumOddNumberFrom1ToN(SumEvenNumberFrom1ToN_UsingDoWhile(N));

	return 0;
}