#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit };

int RandomNumber(int From, int To)
{
	int randNumber;

	randNumber = From + rand() % (From - To + 1);

	return randNumber;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case(enCharType::SmallLetter):
		return char(RandomNumber(97, 122));
		break;

	case(enCharType::CapitalLetter):
		return char(RandomNumber(65, 90));
		break;

	case(enCharType::SpecialCharacter):
		return char(RandomNumber(33, 47));
		break;

	case(enCharType::Digit):
		return char(RandomNumber(48, 57));
		break;

	default:
		return char(RandomNumber(0, 0));
	}
}

short ReadPositiveNumber(string Message)
{
	short Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);

	return Number;
}

string GenerateWord(enCharType CharType,int Length)
{
	string Word = "";

	for (int i = 1; i <= Length; i++)
	{
		Word += GetRandomCharacter(CharType);
		
	}
	return Word;
}

string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key += GenerateWord(enCharType::CapitalLetter, 4);

	return Key;

}

void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key[" << i << "]:" << GenerateKey() << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Pleas enter How many Keys To generate?"));

	return 0;
}





//#include<iostream>
//#include<cstdlib>
//#include <ctime>      // Include ctime for the time() function
//using namespace std;
//
//short ReadPositiveNumber(string Message)
//{
//	short Number;
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//
//	} while (Number < 0);
//	return Number;
//}
//
//int RandomNumber(int From, int To)
//{
//	int randNum = From + rand() % (To - From + 1);
//
//	return randNum;
//}
//
//void GenerateSectionOfKeys()
//{
//	for (int i = 1; i <= 4; i++)
//	{
//		cout << char(RandomNumber(65, 90));
//	}
//}
//
//void GenerateDashSeparator()
//{
//	cout << char(RandomNumber(45, 45));
//}
//
//void GenerateKeys(short Keys)
//{
//	for (int i = 1; i <= Keys; i++)
//	{
//		cout << "Key[" << i << "]:";
//		GenerateSectionOfKeys(); GenerateDashSeparator(); GenerateSectionOfKeys(); GenerateDashSeparator(); GenerateSectionOfKeys(); GenerateDashSeparator(); GenerateSectionOfKeys();
//		cout << "\n";
//	}
//
//}
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	GenerateKeys(ReadPositiveNumber("Pleas enter Number of Keys?"));
//
//	return 0;
//}
