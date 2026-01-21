#include<iostream>
using namespace std;

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

float CalculateReminder(float TotalBill, float TotalCashPaid)
{
	return TotalCashPaid - TotalBill;
}

int main()
{
	float TotalBill = ReadPositiveNumber("Pleas Enter Total bill?");
	float TotalCashPaid = ReadPositiveNumber("Pleas Enter Total Cash paid?");
	
	cout << "\nTotal Bill= " << TotalBill << " $ ";
	cout << "\nTotal Cash Paid= " << TotalCashPaid << " $ ";

	cout << "\n************************\n";
	cout << "The remainder is: " << CalculateReminder(TotalBill, TotalCashPaid) << " $ " << endl;
	

	return 0;

}