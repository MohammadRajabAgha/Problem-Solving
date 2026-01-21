#include<iostream>
#include<string>
#include<cmath>
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

bool IsPerfectNumber(int Number)
{
	int Sum = 0;

	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
			Sum = Sum + i;

	}

	return (Sum == Number);
}

void PrintResult(int Number)
{
	if (IsPerfectNumber(Number))
		cout << Number << " Is Perfect Number.\n";
	else
		cout << Number << " Is NOT Perfect Number.\n";
}

int main()
{
	PrintResult(ReadPositiveNumber("Pleas enter Positive Number?"));

	return 0;
}
