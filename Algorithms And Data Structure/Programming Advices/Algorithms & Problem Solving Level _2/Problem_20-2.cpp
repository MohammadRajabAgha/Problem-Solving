#include<iostream>
#include<cstdlib>
#include <ctime>      // Include ctime for the time() function.
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit };

int RandomNumber(int From, int To)
{
	int randNum = From + rand() % (To - From + 1);

	return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case(enCharType::SmallLetter):
		return char(RandomNumber(97, 122));
		

	case(enCharType::CapitalLetter):
		return char(RandomNumber(65, 90));
		

	case(enCharType::SpecialCharacter):
		return char(RandomNumber(33, 47));
		

	case(enCharType::Digit):
		return char(RandomNumber(48, 57));
		break;

	default:
		return char(RandomNumber(0, 0));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::SmallLetter) << "\n";
	cout << GetRandomCharacter(enCharType::CapitalLetter) << "\n";
	cout << GetRandomCharacter(enCharType::SpecialCharacter) << "\n";
	cout << GetRandomCharacter(enCharType::Digit) << "\n";



	return 0;
}



//#include<iostream>
//#include<cstdlib>
//#include <ctime>      // Include ctime for the time() function.
//using namespace std;
//
//enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit };
//
//void GetCharRange(enCharType Type, int& From, int& To)
//{
//	switch (Type)
//	{
//	case(enCharType::SmallLetter):
//		From = 97; To = 122;
//		break;
//
//	case(enCharType::CapitalLetter):
//		From = 65; To = 90;
//		break;
//
//	case(enCharType::SpecialCharacter):
//		From = 33; To = 47;
//		break;
//
//	case(enCharType::Digit):
//		From = 48; To = 57;
//		break;
//
//	default:
//		From = 0; To = 0;
//	}
//}
//
//int RandomNumber(int From, int To)
//{
//	int randNum = From + rand() % (To - From + 1);
//
//	return randNum;
//}
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int From, To;
//	
//
//	GetCharRange(enCharType::SmallLetter, From, To);
//	cout << char(RandomNumber(From, To)) << endl;
//
//	GetCharRange(enCharType::CapitalLetter, From, To);
//	cout << char(RandomNumber(From, To)) << endl;
//
//	GetCharRange(enCharType::SpecialCharacter, From, To);
//	cout << char(RandomNumber(From, To)) << endl;
//
//	GetCharRange(enCharType::Digit, From, To);
//	cout << char(RandomNumber(From, To)) << endl;
//	return 0;
//}









//#include<iostream>
//#include<cstdlib>
//#include <ctime>      // Include ctime for the time() function.
//using namespace std;
//
//enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit };
//
//void GetCharRange(enCharType Type, int& From, int& To)
//{
//	switch (Type)
//	{
//	case(enCharType::SmallLetter):
//		From = 97; To = 122;
//		break;
//
//	case(enCharType::CapitalLetter):
//		From = 65; To = 90;
//		break;
//
//	case(enCharType::SpecialCharacter):
//		From = 33; To = 47;
//		break;
//
//	case(enCharType::Digit):
//		From = 48; To = 57;
//		break;
//
//	default: 
//		From = 0; To = 0;
//	}
//}
//
//int RandomNumber(int From, int To)
//{
//	int randNum = From + rand() % (To - From + 1);
//
//	return randNum;
//}
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int From, To;
//	int NumberOfenCharType = 0;
//
//	cout << "Pleas enter Your Choice To Print:\n";
//	cout << "*************************************************************\n";
//	cout << "1_Small Letter.\n";
//	cout << "2_Capital Letter.\n";
//	cout << "3_Special Character.\n";
//	cout << "4_Digit.\n";
//	cout << "*************************************************************\n";
//	cin >> NumberOfenCharType;
//
//	enCharType CharType = (enCharType)NumberOfenCharType;
//
//	GetCharRange(CharType, From, To);
//	cout << char(RandomNumber(From, To)) << endl;
//
//	
//	
//
//
//	return 0;
//}
