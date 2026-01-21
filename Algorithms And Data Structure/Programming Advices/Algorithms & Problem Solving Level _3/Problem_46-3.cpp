#include <iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PINCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string Text, string Delim)
{
	vector<string> vString;
	short Pos;
	string sWord;

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

sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PINCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//Cast String To double...

	return Client;
}

void PrintClientCard(sClient Client)
{
	cout << "\n\nThe Following is The extracted Client record : \n";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PINCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone           : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
}

int main()
{
	sClient Client;
	
	string stLine = "A200#//#1234#//#Mohammad Mahmoud Rajab Agha#//#0988212317#//#5000.000000";

	cout << "Line Record is : \n" << stLine;

	Client = ConvertLineToRecord(stLine);

	PrintClientCard(Client);

	system("pause>0");
}