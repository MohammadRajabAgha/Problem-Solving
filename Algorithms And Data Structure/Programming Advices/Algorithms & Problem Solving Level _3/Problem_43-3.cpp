#include <iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

//string ReplaceWords(string Text, string StringToReplace, string sReplaceTo, bool IsMatchCase = true)
//{
//	if (!IsMatchCase)
//	{
//		string tempText = Text;
//		string tempStringToReplace = StringToReplace;
//
//		Text = "";
//		StringToReplace = "";
//
//		for (char& S : tempText)
//		{
//			Text += tolower(S);
//		}
//
//		for (char& S : tempStringToReplace)
//		{
//			StringToReplace += tolower(S);
//		}
//	}
//
//
//	short Pos = Text.find(StringToReplace);
//
//	while (Pos != string::npos)
//	{
//		Text.erase(Pos, StringToReplace.length());
//		Text.insert(Pos, sReplaceTo);
//
//		Pos = Text.find(StringToReplace);
//	}
//
//	return Text;
//}

vector<string> SplitString(string Text, string Delim)
{
	vector<string>vString;
	short Pos = 0;
	string sWord = "";

	while ((Pos = Text.find(Delim)) != std::string::npos)
	{
		sWord = Text.substr(0, Pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		Text.erase(0, Pos + Delim.length());
	}

	if (Text != "")
	{
		vString.push_back(Text);
	}

	return vString;
}

string  LowerAllString(string Text)
{ 
	for (short i = 0; i < Text.length(); i++)
	{ 
		Text[i] = tolower(Text[i]);
	} 
	
	return Text;
}

string JoinString(vector<string> vString, string Delim)
{
	string Text = "";

	for (string& S : vString)
	{
		Text += S + Delim;
	}

	return Text.substr(0, Text.length() - Delim.length());

}

string ReplaceWordsInStringUsingSplit(string Text, string StringToReplace, string sReplaceTo, bool MatchCase = true)
{
	vector<string> vString = SplitString(Text, " ");

	for (string& S : vString)
	{
		if (MatchCase)
		{
			if (S == StringToReplace)
			{
				S = sReplaceTo;
			}
		}

		else
		{
			if (LowerAllString(S) == LowerAllString(StringToReplace))
			{
				S = sReplaceTo;
			}
		}
	}

	return JoinString(vString, " ");

}

int main()
{
	string Text = "Welcom To Syria , Syria is a nice Country\n";

	string StringToReplace = "syria";
	string sReplaceTo = "United Arad Emarites";

	cout << "Origial String\n" << Text;

	cout << "\nReplace With match case : \n";
	cout << ReplaceWordsInStringUsingSplit(Text, StringToReplace, sReplaceTo);

	cout << "\nReplace With don't match case : \n";
	cout << ReplaceWordsInStringUsingSplit(Text, StringToReplace, sReplaceTo, false);


	return 0;
}
                           
/*
                             Origial String
                             Welcom To Syria, Syria is a nice Country
                             
                             Replace With match case:
                             Welcom To Syria, Syria is a nice Country
                             
                             Replace With don't match case :
                             welcom to United Arad Emarites, United Arad Emarites is a nice country
   
*/
