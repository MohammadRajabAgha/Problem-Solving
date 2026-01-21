#include <iostream>
using namespace std;

void ReadArray(int Arr[100], int& arrLength)
{
	cout << "PLease enter Array Length?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Please enter Array[" << i + 1 << "]:";
		cin >> Arr[i];
	}
}

bool IsPalindromeArray(int Arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		if (Arr[i] != Arr[arrLength - i - 1])
			return false;
	}
	return true;
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

	ReadArray(Arr, arrLength);



	cout << "\nArray Elements : ";
	PrintArray(Arr, arrLength);

	if (IsPalindromeArray(Arr, arrLength))
		cout << "Yes, Array is Palindrome.\n";

	else
		cout << "No, Array is Not Palindrome.\n";



	return 0;
}
//Method 1.

//#include <iostream>
//using namespace std;
//
//void ReadArray(int Arr[100], int &arrLength)
//{
//	cout << "PLease enter Array Length?\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength / 2 ; i++)
//	{
//		cout << "Please enter Array[" << i + 1 << "]:";
//		cin >> Arr[i];
//	}
//}
//
//bool IsPalindromeArray(int Arr[100], int arrLength)
//{
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (Arr[i] != Arr[arrLength - i - 1])
//			return false;
//	}
//	return true;
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
//	int Arr[100], arrLength = 0;
//
//	ReadArray(Arr, arrLength);
//
//
//
//	cout << "\nArray Elements:\n";
//	PrintArray(Arr, arrLength);
//
//	if (IsPalindromeArray(Arr, arrLength))
//		cout << "Yes, Array is Palindrome.\n";
//
//	else
//		cout << "No, Array is Not Palindrome.\n";
//
//	
//
//	return 0;
//}

//Method 2.

//#include <iostream>
//using namespace std;
//
//void ReadArray(int Arr[100], int &arrLength)
//{
//	cout << "PLease enter Array Length?\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << "Please enter Array[" << i + 1 << "]:";
//		cin >> Arr[i];
//	}
//}
//
//void ReversedArray(int Arr[100], int Arr2[100], int arrLength)
//{
//	int Count = 0;
//	for (int i = arrLength - 1; i >= 0; i--)
//	{
//		Arr2[Count] = Arr[i];
//		Count++;
//	}
//}
//
//bool IsPalindromeArray(int Arr[100], int Arr2[100], int arrLength)
//{
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (Arr[i] != Arr2[i])
//			return false;
//	}
//	return true;
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
//	int Arr[100], arrLength = 0;
//	int Arr2[100];
//
//	ReadArray(Arr, arrLength);
//
//	cout << "\n";
//
//	ReversedArray(Arr, Arr2, arrLength);
//	PrintArray(Arr2, arrLength);
//
//	
//
//	if (IsPalindromeArray(Arr, Arr2, arrLength))
//		cout << "Yes, Array is Palindrome.\n";
//
//	else
//		cout << "No, Array is Not Palindrome.\n";
//
//	
//
//	return 0;
//}
//

//Method 3.

//#include <iostream>
//using namespace std;
//
//void ReadArray(int Arr[100], int& arrLength)
//{
//	cout << "PLease enter Array Length?\n";
//	cin >> arrLength;
//
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << "Please enter Array[" << i + 1 << "]:";
//		cin >> Arr[i];
//	}
//}
//
//void CopyArray(int Arr[100], int Arr2[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		Arr2[i] = Arr[i];
//	}
//}
//
//void Swap(int& A, int& B)
//{
//	int temp = 0;
//
//	temp = A;
//	A = B;
//	B = temp;
//}
//
//void ReversedArray(int Arr[100], int Arr2[100], int arrLength)
//{
//	CopyArray(Arr, Arr2, arrLength);
//	
//	for (int i = 0 ; i < arrLength/2; i++)
//	{
//		
//		int Index1 = Arr2[arrLength - 1 - i];
//		int Index2 = Arr2[i];
//		Swap(Arr2[Index1], Arr2[Index2]);
//	}
//}
//
//bool IsPalindromeArray(int Arr[100], int Arr2[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (Arr[i] != Arr2[i])
//			return false;
//	}
//	return true;
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
//	int Arr[100], arrLength = 0;
//	int Arr2[100];
//
//	ReadArray(Arr, arrLength);
//
//	cout << "\n";
//	
//	ReversedArray(Arr, Arr2, arrLength);
//	PrintArray(Arr2, arrLength);
//
//
//
//	if (IsPalindromeArray(Arr, Arr2, arrLength))
//		cout << "Yes, Array is Palindrome.\n";
//
//	else
//		cout << "No, Array is Not Palindrome.\n";
//
//
//
//	return 0;
//}

