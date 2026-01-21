#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <fstream>

using namespace std;

//          My Solution Bank 1 .......

//#include <iostream>
//#include<string>
//#include<iomanip>
//#include<cstdio>
//#include<cstdlib>
//#include<fstream>
//#include<vector>
//
//using namespace std;
//
//const string ClientsFileName = "Clients.txt";
//
//struct sClient
//{
//    string AccountNumber;
//    string PINCode;
//    string Name;
//    string Phone;
//    double AccountBalance;
//    bool MarkForDelete = false;
//};
//
//
//enum enChoice { Show = 1, Add, Delete, Update, Find, Exit };
//
//enChoice ReadYourChoice(string Message)
//{
//    int Num;
//    
//    cout << Message;
//    cin >> Num;
//
//    return (enChoice)Num;
//}
//
//void ShowMainMenue()
//{
//    cout << "===========================================\n";
//    cout << "\t\tMain Menue Screen\n";
//    cout << "===========================================\n";
//    cout << "\t[1] Show Clients List.\n";
//    cout << "\t[2] Add New Client.\n";
//    cout << "\t[3] Delete Client.\n";
//    cout << "\t[4] Update Client Info.\n";
//    cout << "\t[5] Find Client.\n";
//    cout << "\t[6] Exit.\n";
//    cout << "===========================================\n";
//}
//
//vector<string>SplitString(string Line,string Delim)
//{
//    vector<string>vClient;
//    int Pos;
//    string sWord;
//
//    while ((Pos = Line.find(Delim)) != string::npos)
//    {
//        sWord = Line.substr(0, Pos);
//
//        if (sWord != "")
//        {
//            vClient.push_back(sWord);
//        }
//
//        Line.erase(0, Pos + Delim.length());
//    }
//
//    if (Line != "")
//    {
//        vClient.push_back(Line);
//    }
//
//    return vClient;
//}
//
//sClient ConvertLineToRecoord(string Line,string Delim)
//{
//    vector <string>vClientData;
//    sClient Client;
//
//    vClientData = SplitString(Line, Delim);
//
//    Client.AccountNumber = vClientData[0];
//    Client.PINCode = vClientData[1];
//    Client.Name = vClientData[2];
//    Client.Phone = vClientData[3];
//    Client.AccountBalance = stod(vClientData[4]);
//
//    return Client;
//}
//
//vector <sClient> LoadDataFromFileToVector(string FileName)
//{
//    vector<sClient> vClientData;
//
//    fstream MyFile;
//    MyFile.open(FileName, ios::in);
//
//   
//    if (MyFile.is_open())
//    {
//        string Line;
//        sClient Client;
//        
//        while (getline(MyFile, Line))
//        {
//            
//            Client = ConvertLineToRecoord(Line, "#//#");
//            vClientData.push_back(Client);
//        }
//    
//        MyFile.close();
//    }
//  
//    return vClientData;
//}
//
//void PrintClientRecord(const sClient &Client)
//{
//    cout << "| " << left << setw(16) << Client.AccountNumber;
//    cout << "| " << left << setw(10) << Client.PINCode;
//    cout << "| " << left << setw(43) << Client.Name;
//    cout << "| " << left << setw(14) << Client.Phone;
//    cout << "| " << left << setw(10) << Client.AccountBalance;
//
//    cout << "\n";
//}
//
//void PrintClients(const vector<sClient> &vClients)
//{
//    cout << "\n\t\t\t\t\t" << "Clients List (" << vClients.size() << ") Client(s).\n";
//
//    cout << "________________________________________________________";
//    cout << "_____________________________________________\n\n";
//
//    cout << setw(17) << "| Account Number  ";
//    cout << setw(12) << "| Pin Code  ";
//    cout << left << setw(45) << "| Client Name ";
//    cout << setw(16) << "| Phone ";
//    cout << setw(11) << "| Balance \n";
//
//    cout << "________________________________________________________";
//    cout << "_____________________________________________\n\n";
//
//    for (const sClient& Client : vClients)
//    {
//
//        PrintClientRecord(Client);
//
//    }
//
//
//    cout << "\n________________________________________________________";
//    cout << "_____________________________________________\n\n";
//
//}
//
//void GoBackToMainMenue()
//{
//    cout << "\n\nPress any Key To go back to Main Menue...";
//    system("pause>0");
//}
//
//bool FindClientsByAccountNumber(const string &AccountNumber, const vector <sClient>& vClients,sClient &Client)
//{
//    for (const sClient& C : vClients)
//    {
//        if (AccountNumber == C.AccountNumber)
//        {
//            Client = C;
//            return true;
//        }
//    }
//
//    return false;
//}
//
//void ReadAccountNumber(string &AccountNumber,vector <sClient>& vClients)
//{
//
//    sClient Client;
//    bool IsFinAccountNumberInFile;
//
//    do
//    {
//        getline(cin >> ws, AccountNumber);
//
//        if (IsFinAccountNumberInFile = FindClientsByAccountNumber(AccountNumber, vClients,Client))
//        {
//            cout << "\nClient With [" << Client.AccountNumber << "] already exists, Enter another Account Number ? ";
//        }
//
//    } while (IsFinAccountNumberInFile);
//}
//
//sClient ReadNewClient(vector <sClient>& vClients)
//{
//    sClient Client;
//
//    cout << "Enter Account Number ? ";
//    ReadAccountNumber(Client.AccountNumber, vClients);
//   
//    cout << "Enter PinCode ? ";
//    getline(cin >> ws, Client.PINCode);
//
//    cout << "Enter Name ? ";
//    getline(cin, Client.Name);
//
//    cout << "Enter Phone ? ";
//    getline(cin, Client.Phone);
//
//    cout << "Enter AccountBalance ? ";
//    cin >> Client.AccountBalance;
//
//    return Client;
//}
//
//void AddNewClient(vector <sClient>& vClients)
//{
//    cout << "---------------------------------------\n";
//    cout << "\tAdd New Clients Screen.\n";
//    cout << "---------------------------------------\n";
//
//    cout << "Adding New Client : \n\n";
//    sClient Client = ReadNewClient(vClients);
//
//    vClients.push_back(Client);
//
//}
//
//string ConvertRecordToLine(sClient Client, string Delim)
//{
//    string Line = "";
//
//    Line = Client.AccountNumber + Delim;
//    Line += Client.PINCode + Delim;
//    Line += Client.Name + Delim;
//    Line += Client.Phone + Delim;
//    Line += to_string(Client.AccountBalance);
//
//    return Line;
//}
//
//void SaveClientsDataToFile(const string &FileName,const vector <sClient> &vClients)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::out);
//
//    if (MyFile.is_open())
//    {
//        string Line;
//
//        for (const sClient& C : vClients)
//        {
//            if (C.MarkForDelete == false)
//            {
//                Line = ConvertRecordToLine(C, "#//#");
//                MyFile << Line << endl;
//            }
//        }
//
//        MyFile.close();
//    }
//}
//
//void AddClients(vector <sClient>& vClients)
//{
//
//    char AddMore = 'Y';
//
//    do
//    {
//        system("cls");
//
//        AddNewClient(vClients);
//        SaveClientsDataToFile(ClientsFileName, vClients);
//
//        cout << "\nClient Added Successfully, Do you want to Add More Clioents : [\'Y\'/\'N\'] ? ";
//        cin >> AddMore;
//
//    } while (AddMore == 'Y' || AddMore == 'y');
//}
//
//void PrintClientCard(const sClient &Client)
//{
//    cout << "\nThe Following is The  Client details : \n";
//    cout << "--------------------------------------\n";
//    cout << "\nAccount Number  : " << Client.AccountNumber;
//    cout << "\nPin Code        : " << Client.PINCode;
//    cout << "\nName            : " << Client.Name;
//    cout << "\nPhone           : " << Client.Phone;
//    cout << "\nAccount Balance : " << Client.AccountBalance;
//    cout << "\n--------------------------------------\n";
//}
//
//void MarkClientForDelete(const string &AccountNumber, vector <sClient>& vClients)
//{
//    for (sClient& C : vClients)
//    {
//        if (AccountNumber == C.AccountNumber)
//        {
//            C.MarkForDelete = true;
//        }
//    }
//}
//
//bool DeletClientsByAccountNumber(vector <sClient> &vClients)
//{
//    cout << "--------------------------------------\n";
//    cout << "\tDelete Clients Screen\n";
//    cout << "--------------------------------------\n";
//
//    sClient Client;
//    char Answer = 'Y';
//
//    cout << "\nPlease enter Account Number ? ";
//    cin >> Client.AccountNumber;
//
//    if (FindClientsByAccountNumber(Client.AccountNumber, vClients,Client))
//    {
//        PrintClientCard(Client);
//
//        cout << "\n\nAre you sure you want delete this client ? \'Y\'/\'N\' ? ";
//        cin >> Answer;
//
//        if (Answer == 'Y' || Answer == 'y')
//        {
//            MarkClientForDelete(Client.AccountNumber, vClients);
//            SaveClientsDataToFile(ClientsFileName, vClients);
//
//            //Refrech Vector
//            vClients = LoadDataFromFileToVector(ClientsFileName);
//
//
//            cout << "\n\nClient Delete Successfully.";
//
//            return true;
//        }
//    }
//
//    else
//    {
//        cout << "\nClient With Account Number (" << Client.AccountNumber << ") is Not Found!";
//
//        return false;
//    }  
//}
//
//sClient ChangeClientReecord(sClient &Client,const string &AccountNumber)
//{
//    Client.AccountNumber = AccountNumber;
//
//    cout << "\n\nEnter PinCode ? ";
//    cin >> Client.PINCode;
//
//    cout << "Enter Name ? ";
//    getline(cin >> ws, Client.Name);
//
//    cout << "Enter Phone ? ";
//    cin >> Client.Phone;
//
//    cout << "Enter Account Balance ? ";
//    cin >> Client.AccountBalance;
//
//    return Client;
//}
//
//bool UpdateClientsByAccountNumber(vector<sClient>& vClients)
//{
//    cout << "----------------------------------------\n";
//    cout << "\tUpdate Client Info Screen";
//    cout << "\n----------------------------------------\n";
//
//    sClient Client;
//    char Answer = 'Y';
//
//    cout << "\nPlease enter Account Number ? ";
//    cin >> Client.AccountNumber;
//
//    if (FindClientsByAccountNumber(Client.AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//
//        cout << "\n\nAre you sure you want to Update this client ? \'Y/\'N ? ";
//        cin >> Answer;
//
//        if (Answer == 'Y' || Answer == 'y')
//        {
//            for (sClient& C : vClients)
//            {
//                if (C.AccountNumber == Client.AccountNumber)
//                {
//                    ChangeClientReecord(C, Client.AccountNumber);
//                }
//            }
//
//            SaveClientsDataToFile(ClientsFileName, vClients);
//
//            cout << "\n\nClient Updated Successfully.\n";
//
//            return true;
//        }
//    }
//
//    else
//    {
//        cout << "\nClient With Account Number (" << Client.AccountNumber << ") is Not Found!";
//
//        return false;
//    }
//}
//
//bool FindClient(vector<sClient>& vClients)
//{
//    cout << "----------------------------------------\n";
//    cout << "\tFind Client Screen";
//    cout << "\n----------------------------------------\n";
//
//    sClient Client;
//    
//    cout << "\nPlease enter Account Number ? ";
//    cin >> Client.AccountNumber;
//
//    if (FindClientsByAccountNumber(Client.AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//
//        return true;
//    }
//
//    else
//    {
//        cout << "\nClient With Account Number (" << Client.AccountNumber << ") is Not Found!";
//
//        return false;
//    }
//
//}
//
//void PrintProgramEnd()
//{
//    cout << "----------------------------------------\n";
//    cout << "\tProgram End :-)";
//    cout << "\n----------------------------------------\n";
//}
//
//void ExcutionChoice(enChoice Choice)
//{
//    vector <sClient> vClients = LoadDataFromFileToVector(ClientsFileName);
//
//    switch (Choice)
//    {
//
//        case enChoice::Show:
//        {
//            system("cls");
//            PrintClients(vClients);
//            GoBackToMainMenue();
//            break;
//        }
//
//        case enChoice::Add:
//        {
//            system("cls");
//            AddClients(vClients);
//            GoBackToMainMenue();
//            break;
//        }
//
//        case enChoice::Delete:
//        {
//            system("cls");
//            DeletClientsByAccountNumber(vClients);
//            GoBackToMainMenue();
//            break;
//        }
//
//        case enChoice::Update:
//        {
//            system("cls");
//            UpdateClientsByAccountNumber(vClients);
//            GoBackToMainMenue();
//            break;
//        }
//
//        case enChoice::Find:
//        {
//            system("cls");
//            FindClient(vClients);
//            GoBackToMainMenue();
//            break;
//        }
//
//        case enChoice::Exit:
//        {
//            system("cls");
//            PrintProgramEnd();
//            break;
//        }
//    }
//}
//
//void StartProgram()
//{
//    enChoice Choice;
//
//    do
//    {
//        system("cls");
//        ShowMainMenue();
//        Choice = ReadYourChoice("Choose What do you want to do ? [1 to 6]? ");
//
//        ExcutionChoice(Choice);
//
//    } while (Choice != enChoice::Exit);
//    
//}
//
//int main()
//{
//    StartProgram();
//
//    system("pause>0");
//}

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string>SplitString(string Text,string Delim)
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

string ConvertRecordToLine(sClient Client,string Seperater="#//#")
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
    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PinCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
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

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
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

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>&vClients)
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

    if (FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        PrintClientCard(Client);
    }

    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }

}

void ShowEndScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tProgram Ends :-) ";
    cout << "\n-------------------------------------\n";
}

enum enMainMenueOption
{
    eListClients=1,eAddNewClient=2,
    eDeleteClient=3,eUpdateClient=4,
    eFindClient=5,eExit=6
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

    cout << "Choose what do you want to do? [1 to 6]? ";
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
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";

    PerformMainMenueChoice((enMainMenueOption)ReadMainMenueOption());
}

int main()
{
    ShowMainMenue();

    system("pause>0");
	return 0;
}