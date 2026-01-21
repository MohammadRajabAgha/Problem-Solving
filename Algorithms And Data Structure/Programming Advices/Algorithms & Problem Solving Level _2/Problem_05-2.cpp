#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PrintDigitsInaReversedOrder(int Number)//important.
{
	int Reminder = 0, int Sum = 0;

	do
	{
		Reminder = Number % 10;//Extract the last digit of Number.
		Number = Number / 10;// Remove the last digit from Number.
		cout << Reminder << "\n";
	} while (Number > 0);
}

int main()
{
	PrintDigitsInaReversedOrder(ReadPositiveNumber("Pleas enter a Positive Number?"));

	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//string ReadPositiveNumber(string Message)
//{
//	int Number;
//
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//
//	return to_string(Number);
//}
//
//int LengthOfString(string MyString)
//{
//	
//
//	return MyString.length();
//
//}
//
//void PrintDigitsInaReversedOrder(string Number)
//{
//	int Length = LengthOfString(Number);
//	cout << "************************************\n";
//	cout << "The Digits In A Reversed Order is:\n";
//
//	for (int i = Length - 1; i >= 0; i--)
//	{
//		cout << Number[i] << "\n";
//	}
//}
//
//int main()
//{
//	PrintDigitsInaReversedOrder(ReadPositiveNumber("Pleas Enter The NUmber?"));
//
//	return 0;
//}