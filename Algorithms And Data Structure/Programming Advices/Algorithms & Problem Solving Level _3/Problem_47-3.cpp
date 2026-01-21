#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<fstream> //To Dealing With Files...

using namespace std; 
 
const string ClientsFileName = "Clients.txt";

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
	getline(cin >> ws, Client.AccountNumber);//To Solve The Problem of Wide Space in cin...

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

void AddDataLineToFile(string FileName, string stDataline)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataline << endl;
	
		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void ResetScreen()
{
	system("cls");
}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		ResetScreen();

		cout << "Adding New Client : \n\n";
		AddNewClient();
	
		cout << "\nClient Added Successfully, Do you want to Add More Clioents : [\'Y\',\'N\'] ? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y' );
}

int main()
{
	AddClients();

	system("pause>0");
}