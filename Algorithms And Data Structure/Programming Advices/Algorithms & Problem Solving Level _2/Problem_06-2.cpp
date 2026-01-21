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

int SumOfDigits(int Number)//important.
{
	int Sum = 0, Reminder = 0;

	while (Number > 0)
	{
		Reminder = Number % 10;//Extract the last digit of Number.
		Number = Number / 10;//Remove the last digit from Number.
		Sum = Sum + Reminder;
	}
	return Sum;
}

int main()
{
	cout << "Sum Of Digits "
		<< SumOfDigits(ReadPositiveNumber("Pleas enter a Positive Number?"))
		<< "\n";

	return 0;
}