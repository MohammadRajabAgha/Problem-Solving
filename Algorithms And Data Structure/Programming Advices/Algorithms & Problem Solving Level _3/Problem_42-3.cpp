#include <iostream>
#include<vector>
#include<string>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string Text, string StringToReplace, string sReplaceTo)
{

	int Pos = Text.find(StringToReplace);

	while (Pos != string::npos)
	{
		Text.replace(Pos, StringToReplace.length(), sReplaceTo);

		Pos = Text.find(StringToReplace);//Find Next....
	}

	return Text;
}

//string ReplaceWords(string Text,string StringToReplace,string sReplaceTo)
//{
//
//	int Pos = Text.find(StringToReplace);
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

int main()
{

	string Text = "Welcom To Syria, Syria is a nice Country\n";

	string StringToReplace = "Syria";
	string sReplaceTo = "United Arad Emarites";

	cout << "Origial String\n" << Text;

	cout << "\nstring After Replace : \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(Text, StringToReplace, sReplaceTo);
	
	sReplaceTo = "USA";

	cout << "\nstring After Replace 2 : \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(Text, StringToReplace, sReplaceTo);


	return 0;
}

/*Mohammad Mahmoud Rajab Agha I'm From Deir Al_Zoor   -->   Al_Zoor Deir From I'm Agha Rajab Mahmoud Mohammad */
