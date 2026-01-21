#include<iostream>
#include<string>
using namespace std;

struct stPiggyBankContent
{
	short Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBankContent ReadPiggyBankContent()
{   
	stPiggyBankContent PiggyBankContent;

	cout << "Pleas enter a Total  Pennies\n";
	cin >> PiggyBankContent.Pennies;

	cout << "Pleas enter a Total Nickels\n";
	cin >> PiggyBankContent.Nickels;

	cout << "Pleas enter a Total Dimes\n";
	cin >> PiggyBankContent.Dimes;

	cout << "Pleas enter a Total Quarters \n";
	cin >> PiggyBankContent.Quarters;

	cout << "Pleas enter a Total Dollars\n";
	cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
	int TotalPennies = 0;

	TotalPennies = PiggyBankContent.Pennies * 1
	             + PiggyBankContent.Nickels * 5
	             + PiggyBankContent.Dimes * 10
	           	 + PiggyBankContent.Quarters * 25
	             + PiggyBankContent.Dollars * 100;
	            
	return TotalPennies;
}

int  main()
{
	int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

	cout << endl<<"Total Pennies = " << TotalPennies << endl;
	cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;
	

	return 0;


} 
