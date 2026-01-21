#include <iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

//string RemovePunctuations(string Text) 
//{
//	string S = ""; 
//	for (short i = 0; i < Text.length(); i++) 
//	{ 
//		if (!ispunct(Text[i])) 
//		{
//			S[i] += Text[i]; 
//		}
//	}
//
//	return S;
//}

string RemovePunctuationsFromString(string Text)
{
	string S = "";

	for (short i = 0; i < Text.length(); i++)
	{
		if (!ispunct(Text[i]))
		{
			S += Text[i];
		}
	}

	return S;
}

int main()
{
	string Text = "Welcom To Syria, Syria is a nice Country; It's amazing.";

	cout << "Origial String\n" << Text;

	cout << "\n\nPunctuation Remove : \n" << RemovePunctuationsFromString(Text) << "\n\n";


	system("pause>0");

}

