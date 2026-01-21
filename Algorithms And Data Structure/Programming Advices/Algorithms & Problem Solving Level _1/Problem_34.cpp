#include<iostream>
using namespace std;

float ReadTotalSales()
{
	float totalsales;

	cout << "Pleas enter Tatal Sales?\n";
	cin >> totalsales;

	return totalsales;
}

float GetComissionPercentage(float TotalSales)
{
	if (TotalSales >= 1000000)
		return 0.01;
	else if (500000 <= TotalSales)
		return 0.02;
	else if (100000 <= TotalSales)
		return 0.03;
	else if (50000 <= TotalSales)
		return 0.05;
	else
		return TotalSales;
}

float CalculateTotalComission(float TotalSales)
{
	return GetComissionPercentage(TotalSales) * TotalSales;
}
int main()
{
	float TotalSales = ReadTotalSales();
	cout << endl << "Comission Percentage = " << GetComissionPercentage(TotalSales) << endl;
	cout << endl << "Total Sales = " << CalculateTotalComission(TotalSales) << endl;

	return 0;

}