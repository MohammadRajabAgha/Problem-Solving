#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int &arrLength)
{
	for (int i = 0; i < arrLength; i++)
		Arr[i] = RandomNumber(1, 100);
}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

void Sum2Array(int Arr[100], int Arr2[100], int ArrSum[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		ArrSum[i] = Arr2[i] + Arr[i];
}

int main()
{
	int Arr[100], Arr2[100], ArrSum[100];
	int arrLength = ReadPositiveNumber("How many elements?\n");

	srand((unsigned)time(NULL));


	FillArrayWithRandomNumbers(Arr, arrLength);
	FillArrayWithRandomNumbers(Arr2, arrLength);


	Sum2Array(Arr, Arr2, ArrSum, arrLength);

	cout << "\nArray 1 Elements:\n";
	PrintArray(Arr, arrLength);

	cout << "\nArray 2 Elements:\n";
	PrintArray(Arr2, arrLength);

	cout << "\nSum of array 1 and array 2 elements :\n";
	PrintArray(ArrSum, arrLength);

	return 0;
}