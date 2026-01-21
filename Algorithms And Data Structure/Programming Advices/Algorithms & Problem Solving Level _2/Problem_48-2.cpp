#include<iostream>
#include<cmath>
using namespace std;

int MyFloor(float Number)
{
	if (Number >= 0)
		return int(Number);
	else
		if (fmod(Number, int(Number) == 0))
			return int(Number);
		else
			return int(Number) - 1;
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
	float Number = ReadNumber();
	cout << "\nMy Floor Result : " << MyFloor(Number) << "\n";
	cout << "C++ Floor Result : " << floor(Number) << "\n";

	return 0;
}

//Method Dr.Mohammed Abu-Hadhoud.

//int MyFloor(float Number)
//{
//	// If the number is positive or zero, return its integer part.
//	if (Number > 0)
//		return int(Number);
//	else
//		// If the number is negative and has a fractional part, subtract 1 to get the floor value.
//		return int(Number) - 1;
//}