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
	cout << "\nPleas enter Number Of Elements ?\n";
	cin >> arrLength;

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

int MAXNumberInArray(int Arr[100], int arrLength)
{
	int MAX = Arr[0];

	for (int i = 1; i < arrLength; i++)
	{
		if (Arr[i] > MAX)
			MAX = Arr[i];
	}

	return MAX;
}

int main()
{
	int Arr[100], arrLength = 0;

	srand((unsigned)time(NULL));

	FillArrayWithRandomNumbers(Arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArray(Arr, arrLength);

	cout << "\nMAX Number is : "
		 << MAXNumberInArray(Arr, arrLength) << endl;

	return 0;
}