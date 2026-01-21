#include<iostream>
#include<string>
using namespace std;

enum enPrimeNOTPrime { Prime = 1, NOTPrime };

enPrimeNOTPrime CheckPrime(int Number)
{
	int M = round(Number / 2);//important.

	for (int i = 2; i < M; i++)
	{
		if (Number % i == 0)
			return enPrimeNOTPrime::NOTPrime;
	}
	return enPrimeNOTPrime::Prime;
}

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void AddArrayElement(int Arr[100], int& arrLength, int Number)
{
	arrLength++;
	Arr[arrLength - 1] = Number;
}

void FillArrayWithRandomNumbers(int Arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);

	}
}

void CopyPrimeNumber(int ArrSource[100], int ArrDestination[100], int arrLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(ArrSource[i])==enPrimeNOTPrime::Prime)
		{
			AddArrayElement(ArrDestination, arrDestinationLength, ArrSource[i]);
		}
	}
}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], arrLength = 0;

	FillArrayWithRandomNumbers(Arr, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr, arrLength);

	int Arr2[100], arr2Length = 0;

	CopyPrimeNumber(Arr, Arr2, arrLength, arr2Length);

	cout << "\nArray 2 Prime Number:\n";
	PrintArray(Arr2, arr2Length);



	return 0;
}
