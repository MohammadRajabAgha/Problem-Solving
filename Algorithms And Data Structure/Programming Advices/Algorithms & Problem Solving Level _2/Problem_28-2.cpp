#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomNumbers(int Arr[100], int& arrLength)
{
	cout << "\nPleas enter How many Number You Want?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
		Arr[i] = RandomNumber(1, 100);

}

void CopyArray(int ArrSource[100], int ArrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		ArrDestination[i] = ArrSource[i];
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
	int Arr[100],Arr2[100], arrLength = 0;

	srand((unsigned)time(NULL));

	FillArrayWithRandomNumbers(Arr, arrLength);

	CopyArray(Arr, Arr2, arrLength);

	cout << "\nArray 1 Elements:\n";
	PrintArray(Arr, arrLength);

	cout << "\nArray 2 Elements after Copy :\n";
	PrintArray(Arr2, arrLength);

	return 0;
}