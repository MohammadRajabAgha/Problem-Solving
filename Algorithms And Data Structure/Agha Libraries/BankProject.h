#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<string>

using namespace std;

const string ClientsFileName = "Clients.txt";

namespace BankProject
{
	struct sClient
	{
		string AccountNumber;
		string PINCode;
		string Name;
		string Phone;
		double AccountBalance;
		bool MarkForDelete = false;
	};

	sClient ReadNewClient()
	{
		sClient Client;

		cout << "Enter Account Number ? ";
		getline(cin >> ws, Client.AccountNumber);

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

	sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
	{
		sClient Client;
		vector<string> vClientData;

		vClientData = StringManipulation::SplitString(Line, Seperator);

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

		} while (toupper(AddMore) == 'Y');
	}

	vector<sClient> LoadClientsDataFromFileToVector(string FileName)
	{
		vector<sClient> vClient;

		fstream MyFile;

		MyFile.open(FileName, ios::in);//Read Mode...

		if (MyFile.is_open())
		{
			string Line;

			sClient Client;

			while (getline(MyFile, Line))
			{

				Client = ConvertLineToRecord(Line);

				vClient.push_back(Client);
			}


			MyFile.close();
		}

		return vClient;

	}

	void PrintClientRecord(sClient Client)
	{
		cout << "| " << left << setw(16) << Client.AccountNumber;
		cout << "| " << left << setw(10) << Client.PINCode;
		cout << "| " << left << setw(43) << Client.Name;
		cout << "| " << left << setw(13) << Client.Phone;
		cout << "| " << left << setw(10) << Client.AccountBalance;

		cout << "\n";
	}

	void PrintClientsData(vector<sClient> vClients)
	{
		cout << "\n\t\t\t\t\t" << "Clients List (" << vClients.size() << ") Client(s).\n";

		cout << "________________________________________________________";
		cout << "_____________________________________________\n\n";

		cout << setw(17) << "| Account Number  ";
		cout << setw(12) << "| Pin Code  ";
		cout << left << setw(45) << "| Client Name ";
		cout << setw(16) << "| Phone ";
		cout << setw(11) << "| Balance \n";

		cout << "________________________________________________________";
		cout << "_____________________________________________\n\n";

		for (sClient& Client : vClients)
		{

			PrintClientRecord(Client);

		}


		cout << "________________________________________________________";
		cout << "_____________________________________________\n\n";

	}

	bool FindClientDataByAccountNumber(string AccountNumber, sClient& Client)
	{
		vector<sClient> vClients = LoadClientsDataFromFileToVector(ClientsFileName);

		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}

		return false;
	}

	bool FindClientDataByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
	{

		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				Client = C;
				return true;
			}
		}

		return false;
	}

	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.MarkForDelete = true;

				return true;
			}
		}

		return false;

	}

	vector<sClient> SaveClientsDataToFile(string FileName, const vector <sClient> vClients)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::out);//Write Mode...

		string DataLine;

		if (MyFile.is_open())
		{
			for (const sClient& C : vClients)
			{
				if (C.MarkForDelete == false)
				{
					DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

		return vClients;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientDataByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);



			cout << "Are you sure you want delete this client ? y/n ? ";
			cin >> Answer;

			if (Answer == 'Y' || Answer == 'y')
			{

				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);


				//Refresh Clients 
				vClients = LoadClientsDataFromFileToVector(ClientsFileName);

				cout << "\n\nClient Delete Successfully.\n";

				return true;
			}
		}

		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";

			return false;
		}
	}

	sClient ChangeClientRecord(string AccountNumber)
	{
		sClient Client;

		Client.AccountNumber = AccountNumber;

		cout << "\nEnter PinCode ? ";
		getline(cin >> ws, Client.PINCode);

		cout << "Enter Name ? ";
		getline(cin, Client.Name);

		cout << "Enter Phone ? ";
		getline(cin, Client.Phone);

		cout << "Enter AccountBalance ? ";
		cin >> Client.AccountBalance;


		return Client;
	}

	bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientDataByAccountNumber(AccountNumber, vClients, Client))
		{
			PrintClientCard(Client);

			cout << "Are you sure you want delete this client ? y/n ? ";
			cin >> Answer;

			if (Answer == 'Y' || Answer == 'y')
			{
				for (sClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
						break;
					}
				}

				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\nClient Delete Successfully.\n";
				return true;
			}
		}

		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n\n";

			return false;
		}
	}

	bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
	{
		vector <sClient> vClients;

		fstream MyFile;

		MyFile.open(FileName, ios::in);//read Modeif 

		if (MyFile.is_open())
		{
			string Line;
			sClient Client;

			while (getline(MyFile, Line))
			{
				Client = ConvertLineToRecord(Line);

				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return true;
				}             vClients.push_back(Client);
			}         MyFile.close();
		}
		return false;
	}
}