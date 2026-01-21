#include<iostream>
#include<string>
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

void ReadArray(int Arr[100], int &arrLength)
{
	cout << "\nPleas enter Number Of Elements:\n";
	cin >> arrLength;

	cout << "\nEnter Array Elements:\n";

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Element[" << i + 1 << "]:";
		cin >> Arr[i];
	}
	cout << "\n";  
}

void PrintArray(int Arr[100], int Length)
{
	
	for (int i = 0; i < Length; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

short TimesRepeated(int Arr[], int NumberToCheck, int Length)
{
	int Count = 0;

	for (int i = 0; i < Length; i++)
	{
		if (NumberToCheck == Arr[i])
			Count++;
	}

	return Count;
}

int main()
{
	int Arr[100]; 
	int arrLength;
	int NumberToCheck = 0;
	

	ReadArray(Arr, arrLength);

	NumberToCheck = ReadPositiveNumber("Pleas enter The Number You Want To Check?");

	cout << "\nOriginal array:"; 
	PrintArray(Arr, arrLength);

	cout << "\nNumber " << NumberToCheck 
		 << " is repeated "
		 << TimesRepeated(Arr, NumberToCheck, arrLength) << " Time(s)\n";

	

	return 0;
}



//#include<iostream>
//#include<string>
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//	int Number;
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number < 0);
//
//	return Number;
//}
//
//void ReadArrayElements(int Arr[100], int Length)
//{
//	for (int i = 0; i < Length; i++)
//	{
//		cin >> Arr[i];
//	}
//	
//}
//
//
//
//
//int main()
//{
//	int Arr[100], Length = 0;
//
//	Length = ReadPositiveNumber("Pleas enter Number Of Elements?");
//
//	ReadArrayElements(Arr, Length);
//
//}
