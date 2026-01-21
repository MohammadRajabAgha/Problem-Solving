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

float GetLoanInstallmentMonths(float LoanAmount,float MonthlyPayment)
{

	return LoanAmount / MonthlyPayment;

}

int main()
{

	float LoanAmount = ReadPositiveNumber("Pleas enter the Loan Amount:");
	float MonthlyPayment = ReadPositiveNumber("Pleas enter the Monthly Payment:");

	cout << "\n"<<"Total Month To Pay " << GetLoanInstallmentMonths(LoanAmount, MonthlyPayment) << " Months" << endl;


	return 0;

}

//#include<iostream>
//using namespace std;
//
//float ReadPositiveNumber(string Message)
//{
//	float Number = 0;
//
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//
//	return Number;
//}
//
//float ReadLoanAmount()
//{
//	return ReadPositiveNumber("Pleas enter the Loan Amount:");
//}
//
//float ReadMonthlyPayment()
//{
//	return ReadPositiveNumber("Pleas enter the Monthly Payment:");
//}
//
//float GetLoanInstallmentMonths()
//{
//
//	return ReadLoanAmount() / ReadMonthlyPayment();
//
//}
//
//int main()
//{
//
//	cout <<"\n" << GetLoanInstallmentMonths() << " Months" << endl;
//
//
//	return 0;
//
//}