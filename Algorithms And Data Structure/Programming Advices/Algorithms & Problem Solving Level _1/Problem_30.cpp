#include<iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

int Factorial(int Number)
{
	int factorial = 1;
	
	for (int Counter = Number; Counter >= 1; Counter--)
	{
		factorial = factorial * Counter;
	}
	
	return factorial;
}


int main()
{
	cout << "\n" << Factorial(ReadPositiveNumber("Pleas enter a Positive Number?")) << endl;

	return 0;

}