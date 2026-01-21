#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << "\n";
		cin >> Number;
	} while (Number < 0);
	return Number;
}

bool IsPerfectNumber(int Number)
{
	int Sum = 0; // Initialize the sum of divisors to 0.

	// Loop from 1 to Number - 1 to find all proper divisors.
	for (int i = 1; i < Number; i++)
	{
		// If i divides Number evenly, it is a divisor.
		if (Number % i == 0)
			Sum += i; // Add the divisor to the sum.
	}

	// Compare the sum of divisors to the original number.
	// Return true if they are equal (the number is perfect), or false if they are not.
	return Number == Sum;
}

void PrintAllPerfectNumberFrom1toN(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << "\n";
		}
	}
}

int main()
{

	PrintAllPerfectNumberFrom1toN(ReadPositiveNumber("Pleas enter a Positive Number?"));

	return 0;
}