#include<iostream>
#include<string>
using namespace std;

void ReadNumber(int &Num1,int &Num2)
{
	

	cout << "Pleas enter Number1?\n";
	cin >> Num1;

	cout << "pleas enter Number2?\n";
	cin >> Num2;

	
}

void SwapOf2Num(int &Num1,int &Num2)
{
	int  temp;

	temp = Num1;
	Num1 = Num2;
	Num2 = temp;
}

void PrintSwapOf2Num(int Num1,int Num2)
{

	cout << "***************************************\n";
	cout << "Number1= " << Num1 << "\n";
	cout << "Number2=" << Num2 << "\n";

}

int main()
{
	int Num1, Num2;
	ReadNumber(Num1,Num2);
	PrintSwapOf2Num(Num1, Num2);
	SwapOf2Num(Num1, Num2);
	PrintSwapOf2Num(Num1, Num2);

		return 0;
}
