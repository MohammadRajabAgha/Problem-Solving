#include<iostream>
#include<string>
using namespace std;

void FillArray(int Arr[100], int& arrLength)
{
	arrLength = 10;

	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 50;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;
	Arr[9] = 90;

}

short FindNumberPositionInArray(int Arr[100], int arrLength, int Number)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (Arr[i] == Number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int Arr[100], int arrLength, int Number)
{
	return FindNumberPositionInArray(Arr, arrLength, Number) != -1;
}

void AddArrayElement(int Arr[100], int& arrLength, int Number)
{
	arrLength++;
	Arr[arrLength - 1] = Number;
}

void CopyDistinctNumber(int ArrSource[100], int ArrDestination[100], int arrLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (!IsNumberInArray(ArrDestination, arrDestinationLength, ArrSource[i]))
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
	int Arr[100], arrLength = 0;

	FillArray(Arr, arrLength);

	cout << "\nArray 2 elements:\n";
	PrintArray(Arr, arrLength);

	int Arr2[100], arr2Length = 0;

	CopyDistinctNumber(Arr, Arr2, arrLength, arr2Length);

	cout << "\nArray 2 Distinct Number:\n";
	PrintArray(Arr2, arr2Length);



	return 0;
}



//#include<iostream>
//#include<string>
//using namespace std;
//
//int TimesRepeated(int Number, int arr[100], int arrLength)
//{
//	int count = 0;
//
//	for (int i = 0; i <= arrLength - 1; i++)
//	{
//		if (Number == arr[i])
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//void AddArrayElement(int Arr[100], int& arrLength, int Number)
//{
//	arrLength++;
//	Arr[arrLength - 1] = Number;
//}
//
//void CopyDistinctNumber(int ArrSource[100], int ArrDestination[100], int arrLength, int& arrDestinationLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (TimesRepeated(ArrSource[i], ArrDestination, arrLength) < 1)
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
//	const int arrLength = 10;
//
//	int Arr[arrLength] = { 10,10,10,50,50,70,70,70,70,90 };
//		
//	cout << "\nArray 1 elements:\n";
//	PrintArray(Arr, arrLength);
//
//	int Arr2[100], arr2Length = 0;
//
//	CopyDistinctNumber(Arr, Arr2, arrLength, arr2Length);
//
//	cout << "\nArray 2 Distinct Number:\n";
//	PrintArray(Arr2, arr2Length);
//
//
//
//	return 0;
//}