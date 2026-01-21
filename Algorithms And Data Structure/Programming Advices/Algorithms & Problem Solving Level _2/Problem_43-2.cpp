#include<iostream>
#include<string>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomNumber(int Arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);

	}
}

int EvenCount(int Arr[100], int arrLength)
{
	int Count = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (Arr[i] % 2 == 0)
			Count++;
	}
	return Count;
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

	FillArrayWithRandomNumber(Arr, arrLength);

	cout << "\nArray elements : ";
	PrintArray(Arr, arrLength);

	cout << "\nEven Number Count is : ";
	cout << EvenCount(Arr, arrLength) << "\n";



	return 0;
}
