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

int ReversedNumber(int Number)//important.
{
	int Sum = 0, Reminder = 0;
	int Number2 = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;//Extract the last digit of Number.
		Number = Number / 10;//Remove the last digit from Number.
		Number2 = Number2 * 10 + Reminder;//Append the digit to Number2 by shifting left and adding Remainder.
	}
	return Number2;;
}

int main()
{
	cout << "Reversed is: \n "
		<< ReversedNumber(ReadPositiveNumber("Pleas enter a Positive Number?"))
		<< "\n";
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//	int Number;
//
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//
//	return Number;
//}
//
//string ReversedNumber(int Number)//important.
//{
//	int Sum = 0, Reminder = 0;
//	string Num;
//
//	while (Number > 0)
//	{
//		Reminder = Number % 10;//Extract the last digit of Number.
//		Num = Num + to_string(Reminder);
//		Number = Number / 10;//Remove the last digit from Number.
//	}
//	return Num;
//}
//
//int main()
//{
//	cout << "Reversed is: \n "
//		<< ReversedNumber(ReadPositiveNumber("Pleas enter a Positive Number?"))
//		<< "\n";
//}
