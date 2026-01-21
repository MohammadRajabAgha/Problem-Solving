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

string GenerateWord(enCharType CharType, int Length)
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

void FillArrayWithKeys(string Arr[100],short arrLength)
{
	for (int i = 0; i <= arrLength; i++)
		Arr[i] = GenerateKey();

}

void PrintStringArray(string Arr[100], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] : ";
		cout << Arr[i] << "\n";
	}

}

int main()
{
	srand((unsigned)time(NULL));

	string Arr[100];
	short arrLength = ReadPositiveNumber("Pleas enter How many Keys To generate?");

	FillArrayWithKeys(Arr, arrLength);

		cout << "\nArray elements:\n\n";
	PrintStringArray(Arr, arrLength);


	return 0;
}

