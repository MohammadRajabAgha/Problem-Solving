#include<iostream>
using namespace std;

short ReadAge()
{
	short Age;

	cout << "Pleas enter Your Age?\n";
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(short Number,short From,short To)
{
	return (Number >= From && Number <= To);
}

void PrintResult(short Age)
{
	if (ValidateNumberInRange(Age,18,45))
	{
		cout << "*************************************\n";
		cout << Age << " is a Valid Age \n";
	}
	else
	{
		cout << "*************************************\n";
		cout << Age << " is a Invalid Age \n";
	}
		
}

int main()
{
	PrintResult(ReadAge());

	return 0;
}