#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NOTPrime };

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int& arrLength)
{
	cout << "\nPlease enter How many Numbers You Want?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		Arr[i] = RandomNumber(1, 100);

}

enPrimeNotPrime CheckPrime(int Number)
{
	short M = round(Number / 2);

	for (int Count = 2; Count <= M; Count++)
	{
		if (Number % Count == 0)
			return enPrimeNotPrime::NOTPrime;
	}
	return enPrimeNotPrime::Prime;
}

void CopyOnlyPrimesNumbers(int ArrSource[100], int ArrDestination[100], int arrLength,int &arr2Length)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(ArrSource[i]) == enPrimeNotPrime::Prime)
		{
			ArrDestination[arr2Length] = ArrSource[i];
			arr2Length++;
		}
	}
}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int Arr[100], arrLength = 0;

	srand((unsigned)time(NULL));

	FillArrayWithRandomNumbers(Arr, arrLength);

	int Arr2[100], arr2Length = 0;

	CopyOnlyPrimesNumbers(Arr, Arr2, arrLength,arr2Length);

	cout << "\nArray 1 Elements:\n";
	PrintArray(Arr, arrLength);

	cout << "\nPrime Number in Array2:\n";
	PrintArray(Arr2, arr2Length);

	return 0;
}