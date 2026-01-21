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

int OddCount(int Arr[100], int arrLength)
{
	int Count = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (Arr[i] % 2 != 0)
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

	

	cout << "\nOdd Number Count is : ";
	cout << OddCount(Arr, arrLength) << "\n";

	
									
	return 0;
}


//Method 2.

//#include<iostream>
//#include<string>
//using namespace std;
//
//int RandomNumber(int From, int To)
//{
//	int randNumber = 0;
//
//	randNumber = From + rand() % (To - From + 1);
//
//	return randNumber;
//}
//
//void AddArrayElement(int Arr[100], int& arrLength, int Number)
//{
//	arrLength++;
//	Arr[arrLength - 1] = Number;
//}
//
//void FillArrayWithRandomNumber(int Arr[100], int& arrLength)
//{
//	cout << "\nEnter number of elements:\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		Arr[i] = RandomNumber(1, 100);
//
//	}
//}
//
//void CopyOddNumber(int ArrSource[100], int ArrDestination[100], int arrLength, int& arrDestinationLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (ArrSource[i] % 2 != 0)
//		{
//			AddArrayElement(ArrDestination, arrDestinationLength, ArrSource[i]);
//		}
//	}
//}
//
//void PrintArray(int Arr[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << Arr[i] << " ";
//	}
//	cout << "\n";
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int Arr[100], arrLength = 0;
//
//	FillArrayWithRandomNumber(Arr, arrLength);
//
//	cout << "\nArray 1 elements:\n";
//	PrintArray(Arr, arrLength);
//
//	int Arr2[100], arr2Length = 0;
//
//	CopyOddNumber(Arr, Arr2, arrLength, arr2Length);
//
//	/*cout << "\nArray 2 Odd Number:\n";
//	PrintArray(Arr2, arr2Length);*/
//
//	cout << "\nOdd Number Count is : " << arr2Length << "\n";
//
//	return 0;
//}
