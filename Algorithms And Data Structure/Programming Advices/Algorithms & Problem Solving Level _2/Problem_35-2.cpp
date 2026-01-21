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
	} while (Number < 0);
	return Number;
}

int RandomNumber(int From, int To)
{
	int randNumber = 0;

	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomNumber(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

short FindNumberPositionInArray(int Arr[100], int arrLength, int NumberToCheck)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (Arr[i] == NumberToCheck)
		{
			return i;
		}

	}

	return -1;
}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n\n";
}

bool IsNumberInArray(int Arr[100], int arrLength,int NumberToCheck)
{
	// Use FindNumberPositionInArray and check if the result is not -1.
	return FindNumberPositionInArray(Arr, arrLength, NumberToCheck) != -1;
}

int main()
{ 

	srand((unsigned)time(NULL));

	int Arr[100], arrLength = 0;
	short NumberToCheck = 0;

	arrLength = ReadPositiveNumber("Please Enter Number OF elements?");

	FillArrayWithRandomNumber(Arr, arrLength);

	cout << "Array 1 elements : ";
	PrintArray(Arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Please enter a Number To Search For ?");
	cout << "\nNumber You are Looking for is : " << NumberToCheck << "\n";


	if (!IsNumberInArray(Arr, arrLength, NumberToCheck))
		cout << "No,The Number is Not Found :-(\n";

	else
		cout << "Yes,The Number is  Found :-)\n";
	

	return 0;
}