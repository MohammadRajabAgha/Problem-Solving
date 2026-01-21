#include<iostream>
#include<string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "PLeas Enter a Number?\n";
	cin >> Number;
	return Number;
}

float CalculateHalfNumber(int Number)
{
	return (float)Number / 2;
}

void PrintHalfNumber(int Number)
{
	string Result = "Half of " + to_string(Number) + " is " + to_string(CalculateHalfNumber(Number));
	cout << "\n" << Result << "\n";
}

int main()
{
	PrintHalfNumber(ReadNumber());

	return 0;
}