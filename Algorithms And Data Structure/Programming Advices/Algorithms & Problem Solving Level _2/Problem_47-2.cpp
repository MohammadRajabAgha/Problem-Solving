#include<iostream>
#include<cmath>
using namespace std;

float GetFractionPart(float Number)
{
	return Number - (int)Number;
}

int MyRound(float Number)
{
	int IntPart = 0;
	IntPart = int(Number);

	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) >= 0.5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

//int MyRound2(float Number)
//{
//	int Reminder = (Number - int(Number)) * 10;
//
//	if (Number > 0)
//	{
//		if (Reminder >= 5)
//			return int(Number) + 1;
//		else
//			return int(Number);
//	}
//
//	if (Number < 0)
//	{
//		Reminder = Reminder * -1;
//
//		if (Reminder >= 5)
//			return (int(Number) - 1);
//		else
//			return int(Number);
//	}
//}

//int MyRound3(float Number)
//{
//	int Reminder = 0;
//
//	if (Number >= 0)
//	{
//		Reminder = fmod(Number, (int)Number) * 10;
//
//		if (Reminder >= 5)
//			return (int)Number + 1;
//		else
//			return (int)Number;
//	}
//
//	else
//	{
//		Number = Number * (-1);
//		Reminder = fmod(Number, (int)Number) * 10;
//		if (Reminder >= 5)
//			return (int)Number * (-1) - 1;
//		else
//			return (int)Number * (-1);
//	}
//
//	
//}

//int MyRound4(float Number)
//{
//	if (Number > 0)
//		return int(Number + 0.5);
//	else
//		return int(Number - 0.5);
//}

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

	cout << "\nMy Round Result : " << MyRound(Number);
	cout << "\nC++ Result : " << round(Number) << "\n";

	return 0;
}









