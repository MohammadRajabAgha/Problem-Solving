#include<iostream>
#include<cmath>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNumber = 0;
	randNumber = From + rand() % (To - From + 1);

	return randNumber;
}

void FillArrayWithRandomArray(int Arr[100], int& arrLength)
{
	cout << "Pleas enter How many elements?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
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

void CopyArrayInReversedOrder(int ArrSource[100], int ArrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		ArrDestination[i] = ArrSource[arrLength - 1 - i];
	}
}

int main()
{
	int Arr[100], Arr2[100], arrLength = 0;

	srand((unsigned)time(NULL));

	FillArrayWithRandomArray(Arr, arrLength);

	cout << "\nArray 1  elements:\n";
	PrintArray(Arr, arrLength);

	CopyArrayInReversedOrder(Arr, Arr2, arrLength);

	cout << "\nArray 2 elements after Copying array 1 in reversed order:\n";
	PrintArray(Arr2, arrLength);

	return 0;
}





//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int RandomNumber(int From, int To)
//{
//	int randNumber = 0;
//	randNumber = From + rand() % (To - From + 1);
//
//	return randNumber;
//}
//
//void Swap(int& A, int& B)
//{
//	int temp;
//
//	temp = A;
//	A = B;
//	B = temp;
//}
//
//void FillArrayWithRandomArray(int Arr[100], int &arrLength)
//{
//	cout << "Pleas enter How many elements?\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		Arr[i] = RandomNumber(1, 100);
//	}
//}
//
//void PrintArray(int Arr[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << Arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void CopyArray(int ArrSource[100], int ArrDestination[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		ArrDestination[i] = ArrSource[i];
//	}
//}
//
//void ArrayReverseOrder(int Arr[100], int arrLength)
//{
//	int M = floor(arrLength / 2);
//
//	for (int i = 0; i < M ; i++)
//	{
//		int index1 = i;
//		int index2 = arrLength - 1 - i;
//
//		Swap(Arr[index1], Arr[index2]);
//
//	}
//}
//
//int main()
//{
//	int Arr[100],Arr2[100], arrLength = 0;
//
//	srand((unsigned)time(NULL));
//
//	FillArrayWithRandomArray(Arr, arrLength);
//
//	cout << "\nArray 1  elements:\n";
//	PrintArray(Arr, arrLength);
//
//	CopyArray(Arr, Arr2, arrLength);
//
//	ArrayReverseOrder(Arr2, arrLength);
//
//	cout << "\nArray 2 elements after Copying array 1 in reversed order:\n";
//	PrintArray(Arr2, arrLength);
//
//	return 0;
//}














//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int RandomNumber(int From, int To)
//{
//	int randNumber = 0;
//	randNumber = From + rand() % (To - From + 1);
//
//	return randNumber;
//}
//
//void FillArrayWithRandomArray(int Arr[100], int& arrLength)
//{
//	cout << "Pleas enter How many elements?\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		Arr[i] = RandomNumber(1, 100);
//	}
//}
//
//void PrintArray(int Arr[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << Arr[i] << " ";
//	}
//	cout << endl;
//}
//
//void CopyArray(int ArrSource[100], int ArrDestination[100], int arrLength)
//{
//	for (int i = 0; i <arrLength; i++)
//	{
//		ArrDestination[i] = ArrSource[i];
//	}
//}
//
//void PrintArrayInReversedOrder(int Arr[100], int arrLength)
//{
//	for (int i = arrLength - 1; i >= 0; i--)
//	{
//		cout << Arr[i] << ' ';
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int Arr[100], Arr2[100], arrLength = 0;
//
//	srand((unsigned)time(NULL));
//
//	FillArrayWithRandomArray(Arr, arrLength);
//
//	cout << "\nArray 1  elements:\n";
//	PrintArray(Arr, arrLength);
//
//	CopyArray(Arr, Arr2, arrLength);
//
//	cout << "\nArray 2 elements after Copying array 1 in reversed order:\n";
//	PrintArrayInReversedOrder(Arr2, arrLength);
//
//	return 0;
//}