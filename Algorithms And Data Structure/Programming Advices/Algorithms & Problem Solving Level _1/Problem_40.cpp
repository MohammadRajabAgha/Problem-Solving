#include<iostream>
#include<string>
using namespace std;

float	const  Services = 1.1;
float const SalesTax = 1.16;

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

float TotalBillAfterServicesAndTax(float BillValue)
{
	return (BillValue * ::Services) * ::SalesTax;
}

void PrintTotalBill()
{
	float BillValue = ReadPositiveNumber("Pleas Enter The Bill Value?");

	cout << "\nTotal Bill: " << BillValue;
	cout << "\nServices: " << ::Services;
	cout << "\nSales Tax: " << ::SalesTax;

	cout << "\n***********************************\n";
	cout << "The Total Bill After Services Fee and Sales Tax= " << TotalBillAfterServicesAndTax(BillValue) << endl;
}
int main()
{
	
	PrintTotalBill();

	return 0;



}