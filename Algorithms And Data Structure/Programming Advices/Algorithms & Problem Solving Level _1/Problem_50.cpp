#include<iostream>
#include<string>
using namespace std;

string ReadPINCode()
{
	string PINCode;
	cout << "Pleas enter PIN Code?\n";
	cin >> PINCode;

	return PINCode;
}

bool Login()
{
	int count = 3;
	string PINCode;

	do
	{
		count--;
		
		PINCode = ReadPINCode();//ReadPin From User هام

		if (PINCode == "1234")
			return true;
		else
		
		system("color 4F");
		cout << "Wrong PIN,You Have " << count << "more tries.\n";
	} while (count >= 1 && PINCode != "1234");

	return false;//This line is redundant ,But Kept for Clarity.
}

int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\nYour Account balance is " << 7500 << '\n';

	}
	else
	{
		system("color 4F");
		cout << "\nYour Card is blocked. Call the bank for help.\n";
	}
	return 0;

}


//#include<iostream> 
//using namespace std;
//
//int checkPIN(int PIN)
//{
//	const int correctPIN = 1234;
//	return (correctPIN == PIN);
//}
//void PrintBalance()
//{
//	const int balance = 7500;
//	cout << "Your Balance is: " << balance << "\n";
//}
//
//void hamdlePIN()
//{
//	int PIN;
//
//	for (int i = 3; i >= 1; i--)
//	{
//		cout << "Pleas enter PIN\n";
//		cin >> PIN;
//
//		if (checkPIN(PIN))
//		{
//			PrintBalance();
//			return;
//		}
//		else
//		{
//			if (i > 1)
//			{
//				cout << "Wrong PIN, You have " << i - 1 << "attempts left.\n";
//			}
//		}
//
//	}
//
//	cout << "Card is Locked!!!\n";
//}
//int main()
//{
//	hamdlePIN();
//
//	return 0;
//}