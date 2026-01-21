#include<iostream>
#include<string>
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

float GetMonthlyInstallmentAmount(float LoanAmount, float HowManyMonth)
{

	return (float)LoanAmount / HowManyMonth;

}

int main()
{

	float LoanAmount = ReadPositiveNumber("Pleas enter the Loan Amount?");
	float HowManyMonth = ReadPositiveNumber("How Many Month?");


	cout << "\n" << "Monthly Installment " << GetMonthlyInstallmentAmount(LoanAmount, HowManyMonth) << "$ Monthly " << endl;

	return 0;

}


//#include<iostream>
//using namespace std;
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
//	return ReadPositiveNumber("Pleas enter the Loan Amount?");
//}
//
//float ReadNumberOfMonth()
//{
//	return ReadPositiveNumber("Pleas enter the Number Of Month?");
//}
//
//float GetMonthlyInstallmentAmount()
//{
//
//	return ReadLoanAmount() / ReadNumberOfMonth();
//
//}
//
//int main()
//{
//
//	cout << "\n" << "You Should Pay " << GetMonthlyInstallmentAmount() << "$ Monthly " << endl;
//
//	return 0;
//
//}
