#include<iostream>
using namespace std;

void ReadNumber(int& Num1, int& Num2)
{

	cout << "Pleas enter a Number 1?\n";
	cin >> Num1;

	cout << "Pleas enter a Number 2?\n";
	cin >> Num2;
}

int CheckMaxOf2Num(int Num1, int Num2)
{
	if (Num1 > Num2)
		return Num1;
	else
		return Num2;
}

void PrintMaxOf2Num(int Max)
{
	cout << "The MAx Number is: " << Max << endl;
}

int main()
{
	int Num1, Num2;

	ReadNumber(Num1, Num2);
	PrintMaxOf2Num(CheckMaxOf2Num(Num1, Num2));
	return 0;
}
