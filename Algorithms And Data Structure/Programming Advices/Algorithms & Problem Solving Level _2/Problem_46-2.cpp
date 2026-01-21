#include<iostream>
#include<cmath>
using namespace std;

float MyABC(float Number)
{
	if (Number > 0)
		return Number;
	else
		return Number * (-1);
}

float ReadNumber()
{
	float Number;
	cout << "PLease enter a Number?\n";
	cin >> Number;
	return Number;
}

int main()
{
	float Number = ReadNumber();

	cout << "My abs Result : " << MyABC(Number) << "\n";
	cout << "C++ abs Result : " << abs(Number) << "\n";

	return 0;
}