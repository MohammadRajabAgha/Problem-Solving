#include<iostream>
#include<cmath>
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyCeil(float Number)
{
	if (abs(GetFractionPart(Number)) > 0)
		if (Number > 0)
			return int(Number) + 1;
		else
			return int(Number);
	else

		return Number;
	
}

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter a Number?\n";
	cin >> Number;

	return Number;
}

int main()
{
	float Number = 0;

	Number = ReadNumber();

	cout << "\nMy Ceil Result : " << MyCeil(Number);
	cout << "\nC++ Ceil Result : " << ceil(Number) << "\n";

	return 0;
}