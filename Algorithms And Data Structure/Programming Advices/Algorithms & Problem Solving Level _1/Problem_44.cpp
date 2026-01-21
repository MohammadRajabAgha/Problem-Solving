#include<iostream>
#include<string>
using namespace std;

enum enDaysOfWeek { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

void PrintList()
{
	cout << "1-Sunday.\n";
	cout << "2-Monday\n";
	cout << "3-Tuesday.\n";
	cout << "4-Wednesday.\n";
	cout << "5-Thursday.\n";
	cout << "6-Friday.\n";
	cout << "7-Saturday.\n";
	cout << "*********************************\n";
	cout << "Pleas enter Your Choice?\n";
}


short ReadNumberInRange(string Message, short From, short To)
{
	short Number;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number<From || Number>To);
	return Number;
}

enDaysOfWeek ReadDayOfWeek()
{
	return (enDaysOfWeek)ReadNumberInRange("Pleas Enter Day Number 1-Sunday = 1\n 2-Monday = 2\n 3-Tuesday = 3\n 4-Wednesday = 4\n 5-Thursday = 5\n 6-Friday = 6\n 7-Saturday = 7\n",1,7);
}

string GetkDayOfWeek(enDaysOfWeek DayOfWeek)//هام
{
	switch (DayOfWeek)
	{

	case(enDaysOfWeek::Sunday):
		return "Sunday.\n";


	case(enDaysOfWeek::Monday):
		return "Monday\n";


	case(enDaysOfWeek::Tuesday):
		return "Tuesday\n";


	case(enDaysOfWeek::Wednesday):
		return "Wednesday\n";



	case(enDaysOfWeek::Thursday):
		return "Thursday\n";


	case(enDaysOfWeek::Friday):
		return"Friday\n";


	case(enDaysOfWeek::Saturday):
		return "Saturday\n";


	default:
		return "Wrong Day\n";

	}

}

int main()
{
	cout << GetkDayOfWeek(ReadDayOfWeek()) << endl;

	return 0;

}


































//#include<iostream>
//#include<string>
//using namespace std;
//
//enum enDaysOfWeek{Sunday=1,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
//
//void PrintList()
//{
//	cout << "1-Sunday.\n";
//	cout << "2-Monday\n";
//	cout << "3-Tuesday.\n";
//	cout << "4-Wednesday.\n";
//	cout << "5-Thursday.\n";
//	cout << "6-Friday.\n";
//	cout << "7-Saturday.\n";
//	cout << "*********************************\n";
//	cout << "Pleas enter Your Choice?\n";
//}
//
//enDaysOfWeek ReadDay()//هام
//{
//	short Day = 0;
//	cin >> Day;
//	enDaysOfWeek DayOfWeek;
//	DayOfWeek = (enDaysOfWeek)Day;
//	cout << "**************************************\n";
//	return DayOfWeek;
//}
//
//string CheckDayOfWeek(enDaysOfWeek DayOfWeek)//هام
//{
//	switch (DayOfWeek)
//	{
//
//	case(enDaysOfWeek::Sunday):
//		return "Sunday.\n";
//	
//
//	case(enDaysOfWeek::Monday):
//		return "Monday\n";
//		
//
//	case(enDaysOfWeek::Tuesday):
//		return "Tuesday\n";
//		
//
//	case(enDaysOfWeek::Wednesday):
//		return "Wednesday\n";
//		
//
//
//	case(enDaysOfWeek::Thursday):
//		return "Thursday\n";
//		
//
//	case(enDaysOfWeek::Friday):
//		return"Friday\n";
//		
//
//	case(enDaysOfWeek::Saturday):
//		return "Saturday\n";
//		
//
//	default:
//		return "Wrong Day\n";
//
//	}
//
//}
//
//int main()
//{
//	PrintList();
//	cout << CheckDayOfWeek(ReadDay()) << endl;
//
//		return 0;
//	
//}