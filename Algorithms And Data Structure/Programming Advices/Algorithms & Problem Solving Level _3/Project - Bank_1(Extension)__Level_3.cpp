#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

void ShowTransactionsMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string>SplitString(string Text, string Delim)
{
    vector<string> vClientData;
    short Pos = 0;
    string sWord;

    while ((Pos = Text.find(Delim)) != string::npos)
    {
        sWord = Text.substr(0, Pos);

        if (sWord != "")
        {
            vClientData.push_back(sWord);
        }

        Text.erase(0, Pos + Delim.length());
    }

    if (Text != "")
    {
        vClientData.push_back(Text);
    }

    return vClientData;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double

    return Client;
}

vector<sClient> LoadCleintsDataFromFileToVector(string FileName)
{
    vector <sClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line = "";
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";

    else
    {
        for (sClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}

bool ClientExistsByAccountNumber(string FileName, string AccountNumber)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }

        MyFile.close();
    }

    return false;
}

sClient ReadNewClient()
{
    sClient Client;

    cout << "\nEnter Account Number ? ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(ClientsFileName, Client.AccountNumber))
    {
        cout << "\nClients With [" << Client.AccountNumber << "] already exists, Enter another Account Number ? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PIN Code ? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Client.Name);

    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperater = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperater;
    stClientRecord += Client.PinCode + Seperater;
    stClientRecord += Client.Name + Seperater;
    stClientRecord += Client.Phone + Seperater;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char Answer = 'n';

    do
    {
        cout << "Adding New Client : \n";

        AddNewClient();

        cout << "\nClient Add Syccessfully, do you want to add more clients ? Y/N ? ";
        cin >> Answer;

    } while (Answer == 'Y' || Answer == 'y');
}

void ShowAddNewClientsScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tAdd New Clients Screen ";
    cout << "\n-------------------------------------\n";

    AddNewClients();
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter Accout Number ? ";
    cin >> AccountNumber;

    return AccountNumber;
}

void PrintClientCard(sClient Client)
{
    cout << "\n\nThe following are the client details : \n";
    cout << "---------------------------------------\n";
    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;
    cout << "\n---------------------------------------\n";

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> &vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
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

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients 
            vClients = LoadCleintsDataFromFileToVector(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

void ShowDeleteClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDelete Client Screen ";
    cout << "\n-------------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PIN Code ? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Client.Name);

    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want Update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);


            cout << "\n\nClient Update Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
        return false;
    }
}

void ShowUpdateClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\nUpdate Client Info Screen ";
    cout << "\n-------------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tFind Client Screen ";
    cout << "\n-------------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    sClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }

    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }

}

bool DepositBalanceToClientByAccoutnNumber(string AccountNumber, vector<sClient>& vClients, double AmountOfChange)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want perform this transactions ? Y/N ?  ";
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        for (sClient& C : vClients)
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

void ShowDepositScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDeposit Screen ";
    cout << "\n-------------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

   while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
   {
      cout << "\nClient With [" << AccountNumber << "] does not exist.\n";

      AccountNumber = ReadClientAccountNumber();
   }


   PrintClientCard(Client);

   double Amount = 0;

   cout << "\nPlease enter deposit amount ? ";
   cin >> Amount;

   DepositBalanceToClientByAccoutnNumber(AccountNumber, vClients, Amount);

}

void ShowWithdrawScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tWithdraw Screen ";
    cout << "\n-------------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient With [" << AccountNumber << "] does not exist.\n";

        AccountNumber = ReadClientAccountNumber();
    }


    PrintClientCard(Client);

    double Amount = 0;

    cout << "\nPlease enter Withdraw amount ? ";
    cin >> Amount;

    //Validate That the amount does not esceeds the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance;

        cout << "\nPlease enter Withdraw amount ? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccoutnNumber(AccountNumber, vClients, (-1) * Amount);
}

void PrintClientRecordBalanceLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector<sClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";

    else
    {
        for (sClient& Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "\t\t\t\t\tTotal Balances = " << TotalBalances;
}

void ShowTotalBalancesScreen()
{
    ShowTotalBalances();
}

enum enTransactionsMenueOption
{
    eDeposit = 1, eWithdraw = 2,
    eShowTotalBalance = 3, eShowMainMenue = 4
};

void GoBackToTransactiosMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();
}

void PerformTransactionsMenueChoice(enTransactionsMenueOption TransactionsMenueOption)
{
    switch (TransactionsMenueOption)
    {

    case enTransactionsMenueOption::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactiosMenue();
        break;
    }

    case enTransactionsMenueOption::eWithdraw:
    {
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactiosMenue();
        break;
    }
   
    case enTransactionsMenueOption::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactiosMenue();
        break;
    }

    case enTransactionsMenueOption::eShowMainMenue:
    {
        ShowMainMenue();
        break;
    }

    }
}

short ReadTransactionsMenueOption()
{
    short Choice = 0;

    cout << "Choose what do you want to do? [1 to 4]? ";
    cin >> Choice;

    return Choice;
}

void ShowTransactionsMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balance.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";

    PerformTransactionsMenueChoice((enTransactionsMenueOption)ReadTransactionsMenueOption());
}

void ShowEndScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tProgram Ends :-) ";
    cout << "\n-------------------------------------\n";
}

enum enMainMenueOption
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eShowTransactionsMenue = 6,
    eExit = 7
};

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void PerformMainMenueChoice(enMainMenueOption MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOption::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOption::eAddNewClient:
    {
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOption::eDeleteClient:
    {
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOption::eUpdateClient:
    {
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOption::eFindClient:
    {
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOption::eShowTransactionsMenue:
    {
        ShowTransactionsMenue();
        break;
    }

    case enMainMenueOption::eExit:
    {
        system("cls");
        ShowEndScreen();
        break;
    }

    }
}

short ReadMainMenueOption()
{
    short Choice = 0;

    cout << "Choose what do you want to do? [1 to 7]? ";
    cin >> Choice;

    return Choice;
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";

    PerformMainMenueChoice((enMainMenueOption)ReadMainMenueOption());
}

int main()
{
    ShowMainMenue();

    system("pause>0");
    return 0;
}