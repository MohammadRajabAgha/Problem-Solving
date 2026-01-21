#include<iostream>
#include<string>
using namespace std;

string ReadPINCode()
{
	string PINCode ;
	cout << "Pleas enter PIN Code?\n";
	cin >> PINCode;
	
	return PINCode;
}

bool Login()
{
	string PINCode;
	do
	{
		PINCode = ReadPINCode();//ReadPin From User هام

		if (PINCode == "1234")
			return true;
		else
			cout << "Wrong PIN\n";
		system("color 4F");
	} while (PINCode != "1234");

	return false;//This line is redundant ,But Kept for Clarity.
}

int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\nYour Account balance is " << 7500 << '\n';

	}

	return 0;

}