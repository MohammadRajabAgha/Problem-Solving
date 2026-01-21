#include<iostream>
#include<string>
#include<cmath>
using namespace std;

enum  enPrimeNotPrime { Prime = 1, NotPrime = 2 };

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Count = 2; Count <= M; Count++)
	{
			if (Number % Count == 0)
				return enPrimeNotPrime::NotPrime;
	
	}
	return enPrimeNotPrime::Prime;  //if you put this in the loop the will take you error result.
}

void PrintNumberType(int Number)
{

	switch (CheckPrime(Number))
	{
	case(enPrimeNotPrime::Prime):
		cout << "The Number is Prime\n";
		break;
	case (enPrimeNotPrime::NotPrime):
		cout << "The Number is Not Prime\n";
		break;
	}
}

int main()
{
	
	PrintNumberType(ReadPositiveNumber("Pleas enter a Positive Number"));

	return 0;
}