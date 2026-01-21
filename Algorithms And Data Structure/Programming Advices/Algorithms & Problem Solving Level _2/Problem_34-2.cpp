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

	short NumberPosition = FindNumberPositionInArray(Arr, arrLength, NumberToCheck);

	if (NumberPosition == -1)
	{
		cout << "\nNumber You are Looking for is : " << NumberToCheck << "\n";
		cout << "The Number is Not Found :-(\n";
	}
	else
	{
		cout << "\nNumber You are Looking for is : " << NumberToCheck << "\n";
		cout << "The Number Found at Position : " << NumberPosition << "\n";
		cout << "The Number Found its Order : " << NumberPosition + 1 << "\n";
	}
	return 0;
}

//#include<iostream>
//#include<string>
//#include<cstdlib>
//#include<ctime>
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//	int Number = 0;
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number < 0);
//	return Number;
//}
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
//void FillArrayWithRandomNumber(int Arr[100], int arrLength)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		Arr[i] = RandomNumber(1, 100);
//	}
//}
//
//bool PrintOrderPositionInArray(int Arr[100], int arrLength, int NumberToCheck, short& Order, short& Index)
//{
//	for (int i = 0; i < arrLength; i++)
//	{
//		if (Arr[i] == NumberToCheck)
//		{
//			cout << "\nNumber You are Looking for is : " << NumberToCheck << "\n";
//			cout << "The Number Found at Position : " << i << "\n";
//			cout << "The Number Found its Order : " << i + 1 << "\n";
//
//			Order = i + 1;
//			Index = i;
//
//			return true;
//		}
//
//	}
//
//	cout << "\nNumber You are Looking for is : " << NumberToCheck << "\n";
//	cout << "The Number is Not Found :-(\n";
//	Order = Index = 0;
//	return false;
//
//
//}
//
//void PrintArray(int Arr[100], int arrLength)
//{
//	cout << "Array 1 elements : ";
//	for (int i = 0; i < arrLength; i++)
//	{
//		cout << Arr[i] << " ";
//	}
//	cout << "\n\n";
//}
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int Arr[100], arrLength = 0;
//	short NumberToCheck = 0, Order, Index;
//
//	arrLength = ReadPositiveNumber("Please Enter Number OF elements?");
//
//	FillArrayWithRandomNumber(Arr, arrLength);
//
//	PrintArray(Arr, arrLength);
//
//	NumberToCheck = ReadPositiveNumber("Please enter a Number To Search For ?");
//
//	PrintOrderPositionInArray(Arr, arrLength, NumberToCheck, Order, Index);
//
//
//
//	cout << "\nThe Result In main:\n";
//	cout << "Position : " << Index << endl;
//	cout << "Order : " << Order << endl;
//
//
//}












//void ArrayWithRandomNumbers(int arr[100], int& arrLength) {
//    for (int i = 0; i < arrLength; i++)
//        arr[i] = RandomNumber(1, 100);
//}
//
//void PositionInArray(int Arr[100], int LengthArr, int SearchNumber, int Position[100], int& LengthPosition)
//{
//    LengthPosition = 0;
//
//    for (int i = 0; i < LengthArr; i++)
//    {
//        if (SearchNumber == Arr[i])
//        {
//            Position[LengthPosition] = i;
//            ++LengthPosition;
//        }
//    }
//}
//
//void PrintPositionInArray(int Position[100], int LengthPosition)
//{
//    switch (LengthPosition)
//    {
//    case 0:
//    {
//        cout << "The Number Is Not Found :-(" << endl;
//        break;
//    }
//    case 1:
//    {
//        cout << "The Number Found in Position: " << Position[0] << endl;
//        break;
//    }
//    default:
//    {
//        int i = 0;
//
//        cout << "The Number Found in Position: " << Position[i];
//
//        for (i = 1; i < LengthPosition; i++)
//        {
//            cout << " And " << Position[i];
//
//        }
//        cout << endl;
//        break;
//    }
//
//    }
//}
//
//void OrderInArray(int Arr[100], int LengthArr, int SearchNumber, int Order[100], int& LengthOrder)
//{
//    LengthOrder = 0;
//
//    for (int i = 0; i < LengthArr; i++)
//    {
//        if (SearchNumber == Arr[i])
//        {
//            Order[LengthOrder] = i + 1;
//            ++LengthOrder;
//        }
//    }
//}
//
//void PrintOrderInArray(int Order[100], int LengthOrder) {
//    switch (LengthOrder)
//    {
//    case 0:
//    {`
//        break;
//    }
//    case 1:
//    {
//        cout << "The Number Find in Order : " << Order[0] << endl;
//        break;
//    }
//    default:
//    {
//        int i = 0;
//
//        cout << "The Number Find in Order : " << Order[i];
//
//        for (i = 1; i < LengthOrder; i++)
//        {
//            cout << " And " << Order[i];
//        }
//        cout << endl;
//        break;
//    }
//    }
//}
//
//void PrintArray(int Arr[100], int LengthArr)
//{
//    for (int i = 0; i < LengthArr; i++)
//    {
//        cout << Arr[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main() {
//    srand((unsigned)time(NULL));
//    int LengthOrderAndPosition = 0;
//    int LengthArr = ReadPositiveNumber("Please enter Number Of elements? ");
//    int Arr[100], Order[100], Position[100];
//
//    ArrayWithRandomNumbers(Arr, LengthArr);
//    cout << "Array elements : \n";
//    PrintArray(Arr, LengthArr);
//
//    int SearchNumber = ReadPositiveNumber("Please enter Number To : ");
//
//    PositionInArray(Arr, LengthArr, SearchNumber, Position, LengthOrderAndPosition);
//    PrintPositionInArray(Position, LengthOrderAndPosition);
//
//    OrderInArray(Arr, LengthArr, SearchNumber, Order, LengthOrderAndPosition);
//    PrintOrderInArray(Order, LengthOrderAndPosition);
//
//    return 0;
//}