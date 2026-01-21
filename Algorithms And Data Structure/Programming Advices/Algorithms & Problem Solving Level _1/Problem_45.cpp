#include<iostream>
#include<string>
using namespace std;

enum enMonthOfYear { January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, 
	                 July = 7, August = 8, September = 9, October = 10, Novemeber = 11, December = 12 };

short ReadNumberInRange(string Message,short From,short To)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number<From || Number>To);
	return Number;
}

enMonthOfYear ReadMonthOfYear()
{
	return (enMonthOfYear)ReadNumberInRange("Pleas enter Number Of Month? \nJanuary = 1. \nFebruary = 2. \nMarch = 3. \nApril = 4. \nMay = 5. \nJune = 6. \nJuly = 7. \nAugust = 8. \nSeptember = 9. \nOctober = 10. \nNovemeber = 11. \nDecember = 12\n",1,12);
}

string GetMonthOfYear(enMonthOfYear Month)
{
	switch (Month)
	{
	case(enMonthOfYear::January):
		return "January\n";
		

	case(enMonthOfYear::February):
		return "February\n";
		

	case(enMonthOfYear::March):
		return "March\n";
		

	case(enMonthOfYear::April):
		return "April\n";
		

	case(enMonthOfYear::May):
		cout << "May\n";
		break;

	case(enMonthOfYear::June):
		 return "June\n";
		

	case(enMonthOfYear::July):
		return "Jule\n";
		


	case(enMonthOfYear::August):
		return "Aigest\n";
		

	case(enMonthOfYear::September):
		return "September\n";
		

	case(enMonthOfYear::October):
		return "October\n";
		

	case(enMonthOfYear::Novemeber):
		return "November\n";
		

	case(enMonthOfYear::December):
		return "December\n";
		

	default:
		return "Worng Month\n";
	}
}

int main()
{
	cout<<GetMonthOfYear(ReadMonthOfYear()) << endl;
	return 0;

}