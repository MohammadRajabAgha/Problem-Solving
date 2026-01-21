#include<iostream>
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

void Swap(int& A, int& B)
{
	int temp;

	temp = A;
	A = B;
	B = temp;
}

int RandomNumber(int From,int To)
{
	int randNumber;
	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayFrom1ToN(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Arr[i] = i + 1;
	}
}

void ShuffleArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		int index1 = RandomNumber(1, arrLength) - 1;
		int index2 = RandomNumber(1, arrLength) - 1;

		Swap(Arr[index1], Arr[index2]);
	}
}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i< arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int Arr[100], arrLength = 0;

	arrLength = ReadPositiveNumber("How many elements?");

	srand((unsigned)time(NULL));

	FillArrayFrom1ToN(Arr, arrLength);

	cout << "\nArray Elements befor shuffle:\n";
	PrintArray(Arr, arrLength);

	ShuffleArray(Arr, arrLength);

	cout << "\nArray Elements after shuffle:\n";
	PrintArray(Arr, arrLength);

}