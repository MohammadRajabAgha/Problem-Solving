#include<iostream>
using namespace std;

void ReadNumber(int& Num1, int& Num2,int &Num3)
{

	cout << "Pleas enter a Number 1?\n";
	cin >> Num1;

	cout << "Pleas enter a Number 2?\n";
	cin >> Num2;

	cout << "Pleas enter a Number 3?\n";
	cin >> Num3;
}

int CheckMaxOf3Num(int Num1, int Num2,int Num3)
{
	int Max = Num1;

	if (Max < Num2)
		Max = Num2;
	if (Max < Num3)
		Max = Num3;

	return Max;

	/*
	
	if(Num1>Num2)
	    if(Num1>Num3)
		     return Num1;

    else if(Num2>Num3)
	      return Num2;

	else 
	  return Num3;
	
	*/
	

}

void PrintMaxOf3Num(int Max)
{
	cout << "The MAx Number is: " << Max << endl;
}

int main()
{
	int Num1, Num2, Num3;

	ReadNumber(Num1, Num2, Num3);
	PrintMaxOf3Num(CheckMaxOf3Num(Num1, Num2, Num3));
	return 0;
}