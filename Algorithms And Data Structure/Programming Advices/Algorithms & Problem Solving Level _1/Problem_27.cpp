#include<iostream>
using namespace std;

int ReadNumber()
{
	int Num;
	cout << "Pleas enter a Number\n";
	cin >> Num;

	return Num;
}

void PrintRangeFrom1ToNumber_UsingWhile(int Number)
{
	int Counter = Number;
	cout << "****************************\n";
	cout << "While Loop\n";
	while (Counter >= 1)
	{
		cout << Counter << "\n";
		Counter--;
	}
}

void PrintRangeFrom1ToNumber_UsingDoWhile(int Number)
{
	int Counter = Number;
	cout << "****************************\n";
	cout << "Do While\n";
	do
	{
		cout << Counter << "\n";
		Counter--;
	} while (Counter >= 1);
}

void PrintRangeFrom1ToNumber_UsingFor(int Number)
{
	cout << "****************************\n";
	cout << "For Loop\n";
	for (int Counter = Number; Counter >= 1; Counter--)
	{
		cout << Counter << "\n";

	}
}

int main()
{
	int N = ReadNumber();

	PrintRangeFrom1ToNumber_UsingWhile(N);
	PrintRangeFrom1ToNumber_UsingDoWhile(N);
	PrintRangeFrom1ToNumber_UsingFor(N);

	return 0;
}