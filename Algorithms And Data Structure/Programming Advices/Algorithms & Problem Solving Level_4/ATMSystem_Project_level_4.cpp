#include <iostream>
#include<vector>
#include<fstream>
#include<string>
#include <cstdlib>

using namespace std;

string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

void ShowMainMenue();
void ShowQuickWithdrawScreen();
void ShowNormalWithdrawScreen();
void ShowDepositScreen();
void Login();

stClient CurrentClient;

vector<string>SplitString(string Text, string Delim)
{
	vector <string> vString;
	string sWord = "";
	short Pos = 0;

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

stClient ConvertLineToClientRecord(string Line, string Delim = "#//#")
{
	vector<string> vClient;

	vClient = SplitString(Line, Delim);

	stClient Client;

	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);

	return Client;
}

vector<stClient> LoadClientDataFromFileToVector(string FileName,string Delim="#//#")
{
	vector<stClient>vClients;

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient C;

		while(getline(MyFile,Line))
		{
			C = ConvertLineToClientRecord(Line);
			vClients.push_back(C);
		}

		MyFile.close();
	}

	return vClients;
}

bool FindClientBuAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& CurrentClient)
{
	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);

	for (stClient &C : vClients)
	{
		if ((C.AccountNumber == AccountNumber) && (C.PinCode == PinCode))
		{
			CurrentClient = C;
			return true;
		}
	}

	return false;
}


enum enMainMenueOptions
{
	eQuickWithdraw = 1, eNormalWithdraw = 2,
	eDeposit = 3, eCheckBalance = 4, eExit = 5
};


string ConvertClientRecordToLine(stClient Client, string Seperater = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperater;
	stClientRecord += Client.PinCode + Seperater;
	stClientRecord += Client.Name + Seperater;
	stClientRecord += Client.Phone + Seperater;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient>& vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient C : vClients)
		{

			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				DataLine = ConvertClientRecordToLine(C);
				MyFile << DataLine << endl;
			}

		}

		MyFile.close();
	}

	return vClients;
}

bool DepositBalanceToClientByAccoutnNumber(string AccountNumber, vector<stClient>& vClients, double AmountOfChange)
{
	char Answer = 'n';

	cout << "\n\nAre you sure you want perform this transactions ? Y/N ?  ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += AmountOfChange;
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfully, New Balance is " << C.AccountBalance;
				return true;
			}
		}

		return false;
	}
}

short ReadQuickWithdrawOption()
{
	short Choice = 0;

	do
	{
		cout << "Choose what to withdraw from [1] To [9] ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice>9);


	return Choice;
}

short GetQuickWithdrawAmount(short QuickWithdrawOption)
{
	short arrQuickWithdarwAmount[] = { 20,50,100,200,400,600,800,1000 };

	return arrQuickWithdarwAmount[QuickWithdrawOption - 1];
}

void PerformQuickWithdrawOption(short QuickWithdrawOption)
{
	if (QuickWithdrawOption == 9)//Exit
	{
		return;
	}

	short WithdrawBalance = GetQuickWithdrawAmount(QuickWithdrawOption);

	if (WithdrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nAmount Exceeds the balance, make another choice.\n";
		cout << "Press Anykey To Continue...";
		system("pause>0");
		ShowQuickWithdrawScreen();
		//return;
	}

	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);
	DepositBalanceToClientByAccoutnNumber(CurrentClient.AccountNumber, vClients, (WithdrawBalance * -1));
	CurrentClient.AccountBalance -= WithdrawBalance;

}

void ShowQuickWithdrawScreen()
{

	system("cls");
	cout << "==============================================\n";
	cout << "\t\tQuick Withdraw\n";
	cout << "==============================================\n";
	cout << "\t[1] 20  \t[2] 50\n";
	cout << "\t[3] 100 \t[4] 200\n";
	cout << "\t[5] 400 \t[6] 600\n";
	cout << "\t[7] 800 \t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "==============================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";

	PerformQuickWithdrawOption(ReadQuickWithdrawOption());

}

int ReadNormalWithdrawAmount()
{
	int Amount = 0;
	
	do
	{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;

	} while (Amount % 5 != 0);

	
	return Amount;
}

void PerformNormalWithdrawOption()
{
	int WithdrawBalance = ReadNormalWithdrawAmount();

	if (WithdrawBalance > CurrentClient.AccountBalance)
	{
		cout << "\nAmount Exceeds the balance, make another choice.\n";
		cout << "Press Anykey To Continue...";
		system("pause>0");
		ShowNormalWithdrawScreen();
		return;
	}

	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);
	DepositBalanceToClientByAccoutnNumber(CurrentClient.AccountNumber, vClients, (WithdrawBalance * -1));
	CurrentClient.AccountBalance -= WithdrawBalance;
}

void ShowNormalWithdrawScreen()
{
	system("cls");
	cout << "==============================================\n";
	cout << "\t\tNormal Withdraw Screen\n";
	cout << "==============================================\n";

	PerformNormalWithdrawOption();
}

double ReadDepositAmount()
{
	double Amount = 0;

	do
	{
		cout << "Enter a Positive Deposit Amount ? ";
		cin >> Amount;

	} while (Amount <= 0);

	return Amount;
}

void PerformDepositOption()
{
	double DepositBalance = ReadDepositAmount();

	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);
	DepositBalanceToClientByAccoutnNumber(CurrentClient.AccountNumber, vClients, DepositBalance);
	CurrentClient.AccountBalance += DepositBalance;
	
}

void ShowDepositScreen()
{
	system("cls");
	cout << "==============================================\n";
	cout << "\t\tDeposit Screen\n";
	cout << "==============================================\n";
	
	PerformDepositOption();

}

void ShowCheckBalanceScreen()
{
	system("cls");
	cout << "==============================================\n";
	cout << "\t\tCheck Balance Screen\n";
	cout << "==============================================\n";
	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
}

void GoBackToMainMenue()
{
	cout << "\n\nPress Anykey To go back To Main Menue...";
	system("pause>0");
	ShowMainMenue();
}

void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::eQuickWithdraw:
	{
		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenue();
		break;
		
	}

	case enMainMenueOptions::eNormalWithdraw:
	{
		system("cls");
		ShowNormalWithdrawScreen();
		GoBackToMainMenue();
		break;
	}

	case enMainMenueOptions::eDeposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenue();
		break;
	}

	case enMainMenueOptions::eCheckBalance:
	{
		system("cls");
		ShowCheckBalanceScreen();
		GoBackToMainMenue();
		break;
	}

	case enMainMenueOptions::eExit:
	{
		system("cls");
		Login();
		break;
	}

	}
}

short ReadMainMenueOption()
{
	short Choice = 0;

	cout << "Choose What do you want to do ? [1 To 5] ? ";
	cin >> Choice;

	return Choice;
}

void ShowMainMenue()
{
	system("cls");
	cout << "==============================================\n";
	cout << "\t\tATM Main Menue Screen\n";
	cout << "==============================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "==============================================\n";

	PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
	if (FindClientBuAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
		return true;
	else
		return false;
	
}

void Login()
{
	string AccountNumber = "";
	string PinCode = "";
	bool LoginFaild = false;

	do
	{
		system("cls");

		cout << "\n-------------------------------------\n";
		cout << "\tLogin Screen";
		cout << "\n-------------------------------------\n";

		if (LoginFaild)
		{
			cout << "Invalid Account Number/Pin Code !.\n";
		}

		cout << "Enter Account Number ? ";
		cin >> AccountNumber;

		cout << "Enter PinCode ? ";
		cin >> PinCode;

		LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

	} while (LoginFaild);


	ShowMainMenue();
}

int main()
{
	Login();

	system("pause>0");
	return 0;
}


//My Solution


//
//#include <iostream>
//#include<vector>
//#include<fstream>
//#include<string>
//#include <cstdlib>
//
//using namespace std;
//
//string ClientsFileName = "Clients.txt";
//
//struct stClient
//{
//	string AccountNumber;
//	string PinCode;
//	string Name;
//	string Phone;
//	double AccountBalance;
//	bool MarkForDelete = false;
//};
//
//void ShowMainMenue();
//void ShowQuickWithdraw();
//void ShowNormalWithdraw();
//void Login();
//
//stClient CurrentClient;
//
//vector<string>SplitString(string Text, string Delim)
//{
//	vector <string> vString;
//	string sWord = "";
//	short Pos = 0;
//
//	while ((Pos = Text.find(Delim)) != std::string::npos)
//	{
//		sWord = Text.substr(0, Pos);
//
//		if (sWord != "")
//		{
//			vString.push_back(sWord);
//		}
//
//		Text.erase(0, Pos + Delim.length());
//	}
//
//	if (Text != "")
//	{
//		vString.push_back(Text);
//	}
//
//	return vString;
//}
//
//stClient ConvertLineToClientRecord(string Line, string Delim = "#//#")
//{
//	vector<string> vClient;
//
//	vClient = SplitString(Line, Delim);
//
//	stClient Client;
//
//	Client.AccountNumber = vClient[0];
//	Client.PinCode = vClient[1];
//	Client.Name = vClient[2];
//	Client.Phone = vClient[3];
//	Client.AccountBalance = stod(vClient[4]);
//
//	return Client;
//}
//
//vector<stClient> LoadClientDataFromFileToVector(string FileName, string Delim = "#//#")
//{
//	vector<stClient>vClients;
//
//	fstream MyFile;
//
//	MyFile.open(FileName, ios::in);
//
//	if (MyFile.is_open())
//	{
//		string Line;
//		stClient C;
//
//		while (getline(MyFile, Line))
//		{
//			C = ConvertLineToClientRecord(Line);
//			vClients.push_back(C);
//		}
//
//		MyFile.close();
//	}
//
//	return vClients;
//}
//
//bool FindClientBuAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& CurrentClient)
//{
//	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);
//
//	for (stClient& C : vClients)
//	{
//		if ((C.AccountNumber == AccountNumber) && (C.PinCode == PinCode))
//		{
//			CurrentClient = C;
//			return true;
//		}
//	}
//
//	return false;
//}
//
//
//enum enMainMenueOptions
//{
//	eQuickWithdraw = 1, eNormalWithdraw = 2,
//	eDeposit = 3, eCheckBalance = 4, eExit = 5
//};
//
//
//string ConvertClientRecordToLine(stClient Client, string Seperater = "#//#")
//{
//	string stClientRecord = "";
//
//	stClientRecord += Client.AccountNumber + Seperater;
//	stClientRecord += Client.PinCode + Seperater;
//	stClientRecord += Client.Name + Seperater;
//	stClientRecord += Client.Phone + Seperater;
//	stClientRecord += to_string(Client.AccountBalance);
//
//	return stClientRecord;
//}
//
//vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient>& vClients)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);//overwrite
//
//	string DataLine;
//
//	if (MyFile.is_open())
//	{
//		for (stClient C : vClients)
//		{
//
//			if (C.MarkForDelete == false)
//			{
//				//we only write records that are not marked for delete.  
//				DataLine = ConvertClientRecordToLine(C);
//				MyFile << DataLine << endl;
//			}
//
//		}
//
//		MyFile.close();
//	}
//
//	return vClients;
//}
//
//bool DepositBalanceToClient(int AmountOfChange)
//{
//	char Answer = 'n';
//
//	cout << "\n\nAre you sure you want perform this transactions ? Y/N ?  ";
//	cin >> Answer;
//
//	vector<stClient>vClients = LoadClientDataFromFileToVector(ClientsFileName);
//
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		for (stClient& C : vClients)
//		{
//			if (CurrentClient.AccountNumber == C.AccountNumber)
//			{
//				C.AccountBalance += AmountOfChange;
//				SaveCleintsDataToFile(ClientsFileName, vClients);
//				cout << "\n\nDone Successfully, New Balance is " << C.AccountBalance;
//				return true;
//			}
//		}
//	}
//	return false;
//
//
//}
//
//void GoBackToQuickWithdrawScreen()
//{
//	cout << "\nAmount Exceeds the balance, make another choice.\n";
//	cout << "Press Anykey To Continue...";
//	system("pause>0");
//	ShowQuickWithdraw();
//}
//
//int ReadQuickWithdrawAmount()
//{
//	short arrQuickWithdraw[] = { 20,50,100,200,400,600,800,1000 };
//	short Choice;
//
//	cout << "Choose what to withdraw from [1] To [8] ? ";
//	cin >> Choice;
//
//	if (Choice == 9)
//		ShowMainMenue();
//
//	short Amount = arrQuickWithdraw[Choice - 1];
//
//	if (Amount > CurrentClient.AccountBalance)
//	{
//		GoBackToQuickWithdrawScreen();
//
//		return ReadQuickWithdrawAmount();
//	}
//
//	return Amount;
//}
//
//void ShowQuickWithdraw()
//{
//	system("cls");
//	cout << "==============================================\n";
//	cout << "\t\tQuick Withdraw\n";
//	cout << "==============================================\n";
//	cout << "\t[1] 20  \t[2] 50\n";
//	cout << "\t[3] 100 \t[4] 200\n";
//	cout << "\t[5] 400 \t[6] 600\n";
//	cout << "\t[7] 800 \t[8] 1000\n";
//	cout << "\t[9] Exit\n";
//	cout << "==============================================\n";
//	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
//}
//
//void ShowQuickWithdrawScreen()
//{
//
//	ShowQuickWithdraw();
//
//	DepositBalanceToClient((-1) * ReadQuickWithdrawAmount());
//
//	LoadClientInfo(CurrentClient.AccountNumber, CurrentClient.PinCode);
//}
//
//void GoBackToNormalWithdrawScreen()
//{
//	cout << "\nAmount Exceeds the balance, make another choice.\n";
//	cout << "Press Anykey To Continue...";
//	system("pause>0");
//	ShowNormalWithdraw();
//}
//
//int ReadNormalWithdrawAmount()
//{
//	int Amount = 0;
//
//	do
//	{
//		cout << "\nEnter an amount multiple of 5's ? ";
//		cin >> Amount;
//
//	} while (Amount % 5 != 0);
//
//	if (Amount > CurrentClient.AccountBalance)
//	{
//		GoBackToNormalWithdrawScreen();
//
//		return ReadNormalWithdrawAmount();
//	}
//
//	return Amount;
//}
//
//void ShowNormalWithdraw()
//{
//	system("cls");
//	cout << "==============================================\n";
//	cout << "\t\tNormal Withdraw Screen\n";
//	cout << "==============================================\n";
//}
//
//void ShowNormalWithdrawScreen()
//{
//	ShowNormalWithdraw();
//	DepositBalanceToClient((-1) * ReadNormalWithdrawAmount());
//
//	LoadClientInfo(CurrentClient.AccountNumber, CurrentClient.PinCode);
//}
//
//int ReadDepositAmount()
//{
//	int Amount = 0;
//
//	do
//	{
//		cout << "Enter a Positive Deposit Amount ? ";
//		cin >> Amount;
//
//	} while (Amount < 0);
//
//	return Amount;
//}
//
//void ShowDepositScreen()
//{
//	system("cls");
//	cout << "==============================================\n";
//	cout << "\t\tDeposit Screen\n";
//	cout << "==============================================\n";
//
//	DepositBalanceToClient(ReadDepositAmount());
//
//	LoadClientInfo(CurrentClient.AccountNumber, CurrentClient.PinCode);
//}
//
//void ShowCheckBalanceScreen()
//{
//	system("cls");
//	cout << "==============================================\n";
//	cout << "\t\tCheck Balance Screen\n";
//	cout << "==============================================\n";
//	cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";
//}
//
//void GoBackToMainMenue()
//{
//	cout << "\n\nPress Anykey To go back To Main Menue...";
//	system("pause>0");
//	ShowMainMenue();
//}
//
//void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
//{
//	switch (MainMenueOption)
//	{
//	case enMainMenueOptions::eQuickWithdraw:
//	{
//		system("cls");
//		ShowQuickWithdrawScreen();
//		GoBackToMainMenue();
//		break;
//
//	}
//
//	case enMainMenueOptions::eNormalWithdraw:
//	{
//		ShowNormalWithdrawScreen();
//		GoBackToMainMenue();
//		break;
//	}
//
//	case enMainMenueOptions::eDeposit:
//	{
//		ShowDepositScreen();
//		GoBackToMainMenue();
//		break;
//	}
//
//	case enMainMenueOptions::eCheckBalance:
//	{
//		system("cls");
//		ShowCheckBalanceScreen();
//		GoBackToMainMenue();
//		break;
//	}
//
//	case enMainMenueOptions::eExit:
//	{
//		Login();
//		break;
//	}
//
//	}
//}
//
//short ReadMainMenueOption()
//{
//	short Choice = 0;
//
//	cout << "Choose What do you want to do ? [1 To 5] ? ";
//	cin >> Choice;
//
//	return Choice;
//}
//
//void ShowMainMenue()
//{
//	system("cls");
//	cout << "==============================================\n";
//	cout << "\t\tATM Main Menue Screen\n";
//	cout << "==============================================\n";
//	cout << "\t[1] Quick Withdraw.\n";
//	cout << "\t[2] Normal Withdraw.\n";
//	cout << "\t[3] Deposit.\n";
//	cout << "\t[4] Check Balance.\n";
//	cout << "\t[5] Logout.\n";
//	cout << "==============================================\n";
//
//	PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
//}
//
//bool LoadClientInfo(string AccountNumber, string PinCode)
//{
//	if (FindClientBuAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
//		return true;
//	else
//		return false;
//
//}
//
//void Login()
//{
//	string AccountNumber = "";
//	string PinCode = "";
//	bool LoginFaild = false;
//
//	do
//	{
//		system("cls");
//
//		cout << "\n-------------------------------------\n";
//		cout << "\tLogin Screen";
//		cout << "\n-------------------------------------\n";
//
//		if (LoginFaild)
//		{
//			cout << "Invalid Account Number/Pin Code !.\n";
//		}
//
//		cout << "Enter Account Number ? ";
//		cin >> AccountNumber;
//
//		cout << "Enter PinCode ? ";
//		cin >> PinCode;
//
//		LoginFaild = !LoadClientInfo(AccountNumber, PinCode);
//
//	} while (LoginFaild);
//
//
//	ShowMainMenue();
//}
//
//int main()
//{
//	Login();
//
//	system("pause>0");
//	return 0;
//}
