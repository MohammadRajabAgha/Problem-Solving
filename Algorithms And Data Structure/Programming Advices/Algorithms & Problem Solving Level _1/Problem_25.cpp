#include<iostream>
using namespace std;

short ReadAge()
{
	short Age;

	cout << "Pleas enter Your Age between 18 and 45?\n";;
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(short Number, short From, short To)
{
	return (Number >= From && Number <= To);
}

short ReadUntilAgeBetween(short From, short To)
{
	short Age = 0;
	
	do
	{
		Age = ReadAge();
	} while (!ValidateNumberInRange(Age, 18, 45));

	return Age;
}

void PrintResult(short Age)
{
	cout << "Your Age is: " << Age << endl;
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18,45));

	return 0;
}