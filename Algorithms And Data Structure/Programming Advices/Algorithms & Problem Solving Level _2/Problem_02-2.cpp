#include<iostream>
#include<string>
using namespace std;

enum  enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

void PrintNumberFrom1ToN(int Number)
{

	cout << "\nPrime Number From 1 To " << Number 
		 << " are : \n";

	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
			cout << i << "\n";
	}
}

int main()
{

	PrintNumberFrom1ToN(ReadPositiveNumber("Pleas enter a Positive Number?"));

}