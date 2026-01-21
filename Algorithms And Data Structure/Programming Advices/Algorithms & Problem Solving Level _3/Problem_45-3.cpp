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

sClient ReadNewClient()
{
	sClient Client;

	cout << "Enter Account Number ? ";
	getline(cin, Client.AccountNumber);

	cout << "Enter PinCode ? ";
	getline(cin, Client.PINCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone ? ";
	getline(cin, Client.Phone);
	
	cout << "Enter AccountBalance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperater = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperater;
	stClientRecord += Client.PINCode + Seperater;
	stClientRecord += Client.Name + Seperater;
	stClientRecord += Client.Phone + Seperater;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{
	sClient Client;

	cout << "Please Enter Client Data : \n\n";
	Client = ReadNewClient();

	cout << "\n\nClient Record for Saving is : \n";
	cout << ConvertRecordToLine(Client);


	system("pause>0");

}