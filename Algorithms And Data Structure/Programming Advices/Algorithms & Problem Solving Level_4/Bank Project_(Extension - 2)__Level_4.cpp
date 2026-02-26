#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include <fstream>
#include<cmath>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

struct stUser
{
    string Username;
    string Password;
    short Permissions = -1;
    bool MarkForDelete = false;
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

enum enMainMenuePermissions
{
    pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64
};

stUser CurrentUser;

void ShowMainMenue();
void ShowTransactionsMenue();
void Login();
void ShowManageUsersMenue();

bool CheckAccessPermission(enMainMenuePermissions MainMenuePermissions)
{
    if (CurrentUser.Permissions == enMainMenuePermissions::pAll)
        return true;

    return ((CurrentUser.Permissions & MainMenuePermissions) == MainMenuePermissions);
}

void ShowAccessDeniedMessage()
{
    system("cls");
    cout << "\n-------------------------------------\n";
    cout << "Access Denied, \n";
    cout << "You don't Have Permission To Do this, \n";
    cout << "Please conact Your Admin.";
    cout << "\n-------------------------------------\n";
}

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

stClient ConvertLinetoClientRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double

    return Client;
}

vector<stClient> LoadCleintsDataFromFileToVector(string FileName)
{
    vector <stClient> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line = "";
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoClientRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

stUser ConvertLineToUserRecord(string Line)
{
    stUser User;
    vector<string> vUsers;

    vUsers = SplitString(Line, "#//#");

    User.Username = vUsers[0];
    User.Password = vUsers[1];
    User.Permissions = stoi(vUsers[2]);

    return User;
}

bool FindUserByUsername(string Username, vector <stUser> vUsers, stUser& User)
{

    for (stUser U : vUsers)
    {

        if (U.Username == Username)
        {
            User = U;
            return true;
        }

    }
    return false;

}

vector<stUser> LoadUsersDataFromFileToVector(string FileName, string Seperater = "#//#")
{
    vector<stUser> vUsers;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line = "";
        stUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertLineToUserRecord(Line);
            vUsers.push_back(User);
        }

        MyFile.close();

    }


    return vUsers;
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& CurrentUser)
{
    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName);

    for (stUser& U : vUsers)
    {
        if (U.Username == Username && U.Password == Password)
        {
            CurrentUser = U;
            return true;
        }
    }
   
    return false;
} 

void PrintClientRecordLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector <stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);

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
        for (stClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
{
    for (stClient C : vClients)
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
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoClientRecord(Line);
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

stClient ReadNewClient()
{
    stClient Client;

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
    stClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertClientRecordToLine(Client));
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

    if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

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

void PrintClientCard(stClient Client)
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

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{

    for (stClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
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

bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
{
    stClient Client;
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
    if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\tDelete Client Screen ";
    cout << "\n-------------------------------------\n";

    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;

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

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want Update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient& C : vClients)
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
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\nUpdate Client Info Screen ";
    cout << "\n-------------------------------------\n";

    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{

    if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "\tFind Client Screen ";
    cout << "\n-------------------------------------\n";

    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
    }

    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
    }

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

void ShowDepositScreen()
{
    cout << "\n-------------------------------------\n";
    cout << "\tDeposit Screen ";
    cout << "\n-------------------------------------\n";

    stClient Client;

    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
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

    stClient Client;

    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
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

void PrintClientRecordBalanceLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);

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
        for (stClient& Client : vClients)
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
    if (!CheckAccessPermission(enMainMenuePermissions::pTransactions))
    {
        ShowAccessDeniedMessage();
        return;
    }


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

void PrintUsersRecord(stUser User)
{
    cout << "| " << left << setw(15) << User.Username;
    cout << "| " << left << setw(12) << User.Password;
    cout << "| " << left << setw(40) << User.Permissions;
}

void ShowAllUsersScreen()
{


    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");

    cout << "\n\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(12) << "PassWord";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________________________________________\n\n";

    for (stUser& User : vUsers)
    {
        PrintUsersRecord(User);
        cout << endl;
    }

    cout << "\n_______________________________________________________________________________________\n\n";

}

void ShowListUsersScreen()
{
    ShowAllUsersScreen();
}

enum enManageUsersOption
{
    eListUsers = 1, eAddNewUser = 2,
    eDeleteUser = 3, eUpdateUser = 4,
    eFindUser = 5, eMainMenue = 6
};

short ReadManageUsersChoice()
{
    short Choice = 0;

    cout << "Choose What Do you want to do ? [1 to 6] ? ";
    cin >> Choice;

    return Choice;
}

void GoBackToManageUsersScreen(stUser CurrentUser)
{
    cout << "\n\nPress any key to go back to Manage Users...";
    system("pause>0");
    ShowManageUsersMenue();
}

string ConvertUserRecordToLine(stUser User, string Delim = "#//#")
{
    string Line = "";

    Line = User.Username + Delim;
    Line += User.Password + Delim;
    Line += to_string(User.Permissions);

    return Line;
}

bool UserExistsByUsername(string Username, stUser& CurrentUser)
{
    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");

    for (stUser User : vUsers)
    {
        if (User.Username == Username)
        {
            CurrentUser.Username = User.Username;
            CurrentUser.Password = User.Password;
            CurrentUser.Permissions = User.Permissions;
            return true;
        }
    }
    return false;
}

short ReadPermissionsToSet()
{
    short Permissions = 0;

    char Approve = 'y';
    cout << "\nDo You want to give full access ? Y/N ? ";
    cin >> Approve;

    if (toupper(Approve) == 'Y')
        return -1;


    cout << "\n\nDo you want to give access to : ";


    cout << "\n\nShow Client List ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 1;


    cout << "\nAdd New Client ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 2;

    cout << "\nDelete Client ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 4;

    cout << "\nUpdate Client ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 8;

    cout << "\nFind Client ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 16;

    cout << "\nTransactions ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 32;

    cout << "\nManage Users ? Y/N ? ";
    cin >> Approve;
    if (toupper(Approve) == 'Y')
        Permissions += 64;


    return Permissions;
}

stUser ReadNewUser()
{
    stUser NewUser;

    cout << "Enter Username ? ";
    getline(cin >> ws, NewUser.Username);

    while (UserExistsByUsername(NewUser.Username, NewUser))
    {
        cout << "\nUser With [" << NewUser.Username << "] already exists, Enter another username ? ";
        getline(cin >> ws, NewUser.Username);
    }

    cout << "Enter Password ? ";
    getline(cin, NewUser.Password);

    NewUser.Permissions = ReadPermissionsToSet();

    return NewUser;
}

void AddNewUser()
{
    stUser User;
    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
}

void AddNewUsers()
{
    char AddMore = 'N';

    do
    {
        cout << "\nAdding New User : \n\n";

        AddNewUser();

        cout << "\nUser Add Successfully, Do you want to add more users ? Y/N ? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

void ShowAddNewUsersScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tAdd New User Screen.";
    cout << "\n----------------------------------------";

    AddNewUsers();
}

void PrintUserCard(stUser User)
{
    cout << "\n\nThe following are the User details : \n";
    cout << "---------------------------------------\n";
    cout << "\nUsername    : " << User.Username;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n---------------------------------------\n";
}

bool MarkUserForDeleteByUsername(string Username, vector<stUser>& vUsers)
{
    for (stUser& User : vUsers)
    {
        if (User.Username == Username)
        {
            User.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

vector<stUser>SaveUsersDataToFile(string FileName, vector<stUser>& vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (stUser U : vUsers)
        {

            if (U.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertUserRecordToLine(U);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vUsers;
}

bool DeleteUserByUsername(string Username, vector<stUser>& vUsers)
{

    if (Username == "Admin")
    {
        cout << "\n\nYou Can not Delete This User.";
        return false;
    }

    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers,User))
    {
        PrintUserCard(User);

        cout << "\n\nAre you sure you want delete this User? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkUserForDeleteByUsername(User.Username, vUsers);
            SaveUsersDataToFile(UsersFileName, vUsers);

            //Refresh Clients 
            vUsers = LoadUsersDataFromFileToVector(UsersFileName);

            cout << "\n\nUsert Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }

}

string ReadUserName()
{
    string Username = "";

    cout << "\nPlease enter Username? ";
    cin >> Username;
    return Username;

}

void showDeleteUserScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tDelete User Screen.";
    cout << "\n----------------------------------------";

    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");

    string Username = ReadUserName();

    DeleteUserByUsername(Username, vUsers);

}

stUser ChangeUserRecord(string Username)
{
    stUser User;

    User.Username = Username;

    cout << "\n\nEnter Password ? ";
    getline(cin >> ws, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}

bool UpdateUserByUsername(string Username, vector<stUser>& vUsers)
{
    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User))
    {
        PrintUserCard(User);

        cout << "\n\nAre you sure you want Update this User? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stUser& U : vUsers)
            {
                if (U.Username == Username)
                {
                    U = ChangeUserRecord(Username);
                    break;
                }
            }

            SaveUsersDataToFile(UsersFileName, vUsers);


            cout << "\n\nUser Update Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }

}

void ShowUpdateUserScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tUpdate User Screen.";
    cout << "\n----------------------------------------";

    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");

    string Username = ReadUserName();

    UpdateUserByUsername(Username, vUsers);
}

void ShowFindUserScreen()
{
    cout << "\n----------------------------------------\n";
    cout << "\tFind User Screen.";
    cout << "\n----------------------------------------";

    vector <stUser> vUsers = LoadUsersDataFromFileToVector(UsersFileName);

    string Username;
    stUser User;

    Username = ReadUserName();

    if (FindUserByUsername(Username, vUsers, User))
    {
        PrintUserCard(User);
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!\n";
    }
}

void PerformManageUsersMenueChoice(enManageUsersOption ManageUsersOption)
{
    switch (ManageUsersOption)
    {
    case enManageUsersOption::eListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersScreen(CurrentUser);
        break;
    }

    case enManageUsersOption::eAddNewUser:
    {
        system("cls");
        ShowAddNewUsersScreen();
        GoBackToManageUsersScreen(CurrentUser);
        break;
    }

    case enManageUsersOption::eDeleteUser:
    {
        system("cls");
        showDeleteUserScreen();
        GoBackToManageUsersScreen(CurrentUser);
        break;
    }

    case enManageUsersOption::eUpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersScreen(CurrentUser);
        break;
    }

    case enManageUsersOption::eFindUser:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersScreen(CurrentUser);
        break;
    }

    case enManageUsersOption::eMainMenue:
    {
        ShowMainMenue();
        break;
    }
    default:
        ShowMainMenue();
        break;

    }
}

void ShowManageUsersMenue()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();
        return;
    }

    system("cls");
    cout << "==================================================\n";
    cout << "\t\tManage Users Menue Screen.\n";
    cout << "==================================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "==================================================\n";

    PerformManageUsersMenueChoice((enManageUsersOption)ReadManageUsersChoice());
}

enum enMainMenueOption
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eShowTransactionsMenue = 6,
    eMangeUsers = 7, eExit = 8
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

    case enMainMenueOption::eMangeUsers:
    {
        ShowManageUsersMenue();
        break;
    }

    case enMainMenueOption::eExit:
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

    cout << "Choose what do you want to do? [1 to 8]? ";
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";

   PerformMainMenueChoice((enMainMenueOption)ReadMainMenueOption());

}

bool LoadUserInfo(string Username, string Password)
{
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;

    else
        return false;
}

void Login()
{

    string Username, Password;

    bool LoginFailed = false;

    do
    {
        system("cls");
        cout << "\n------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n------------------------------\n";

        if (LoginFailed)
        {
            cout << "Invalid Username/Password !\n";
        }

        cout << "Enter Username ? ";
        getline(cin >> ws, Username);

        cout << "Enter Password ? ";
        getline(cin, Password);

       
        LoginFailed = !LoadUserInfo(Username, Password);

    } while (LoginFailed);

    ShowMainMenue();
}

int main()
{
    Login();

    system("pause>0");
    return 0;
}




//My Solution...

//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<vector>
//#include <fstream>
//#include<cmath>
//
//using namespace std;
//
//const string ClientsFileName = "Clients.txt";
//const string UsersFileName = "Users.txt";
//
//struct stUser
//{
//    string Username;
//    string Password;
//    short Permissions = -1;
//    bool MarkForDelete = false;
//};
//
//void ShowMainMenue(stUser CurrentUser);
//void ShowTransactionsMenue(stUser CurrentUser);
//void Login();
//void ShowManageUsersMenue(stUser CurrentUser);
//
//struct stClient
//{
//    string AccountNumber;
//    string PinCode;
//    string Name;
//    string Phone;
//    double AccountBalance;
//    bool MarkForDelete = false;
//};
//
//vector<string>SplitString(string Text, string Delim)
//{
//    vector<string> vClientData;
//    short Pos = 0;
//    string sWord;
//
//    while ((Pos = Text.find(Delim)) != string::npos)
//    {
//        sWord = Text.substr(0, Pos);
//
//        if (sWord != "")
//        {
//            vClientData.push_back(sWord);
//        }
//
//        Text.erase(0, Pos + Delim.length());
//    }
//
//    if (Text != "")
//    {
//        vClientData.push_back(Text);
//    }
//
//    return vClientData;
//}
//
//stClient ConvertLinetoClientRecord(string Line, string Seperator = "#//#")
//{
//    stClient Client;
//    vector<string> vClientData;
//
//    vClientData = SplitString(Line, Seperator);
//
//    Client.AccountNumber = vClientData[0];
//    Client.PinCode = vClientData[1];
//    Client.Name = vClientData[2];
//    Client.Phone = vClientData[3];
//    Client.AccountBalance = stod(vClientData[4]);//cast string to double
//
//    return Client;
//}
//
//vector<stClient> LoadCleintsDataFromFileToVector(string FileName)
//{
//    vector <stClient> vClients;
//
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line = "";
//        stClient Client;
//
//        while (getline(MyFile, Line))
//        {
//            Client = ConvertLinetoClientRecord(Line);
//            vClients.push_back(Client);
//        }
//
//        MyFile.close();
//    }
//
//    return vClients;
//}
//
//stUser ConvertLineToUserRecord(string Line)
//{
//    stUser User;
//    vector<string> vUsers;
//
//    vUsers = SplitString(Line, "#//#");
//
//    User.Username = vUsers[0];
//    User.Password = vUsers[1];
//    User.Permissions = stoi(vUsers[2]);
//
//    return User;
//}
//
//bool FindUserByUsernameAndPassword(string FileName, string Username, string Password, stUser &CurrentUser)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line;
//        stUser User;
//
//        while (getline(MyFile, Line))
//        {
//            User = ConvertLineToUserRecord(Line);
//
//            if (User.Username == Username)
//            {
//                if (User.Password == Password)
//                {
//                    CurrentUser.Permissions = User.Permissions;
//                    MyFile.close();
//
//                    CurrentUser.Permissions = User.Permissions;
//
//                    return true;
//                }
//            }
//        }
//
//    }
//
//
//    MyFile.close();
//
//    return false;
//}
//
//void ShowLoginScreen()
//{
//    system("cls");
//    cout << "\n------------------------------\n";
//    cout << "\tLogin Screen";
//    cout << "\n------------------------------\n";
//}
//
//stUser ReadLoginInfo()
//{
//    stUser User;
//
//    cout << "Enter Username ? ";
//    getline(cin >> ws, User.Username);
//
//    cout << "Enter Password ? ";
//    getline(cin, User.Password);
//
//    while (!FindUserByUsernameAndPassword(UsersFileName, User.Username, User.Password, User))
//    {
//        ShowLoginScreen();
//
//        cout << "Invalid Username/Password !\n";
//
//        cout << "Enter Username ? ";
//        getline(cin >> ws, User.Username);
//
//        cout << "Enter Password ? ";
//        getline(cin, User.Password);
//
//    }
//
//    return User;
//}
//
//void PrintClientRecordLine(stClient Client)
//{
//    cout << "| " << setw(15) << left << Client.AccountNumber;
//    cout << "| " << setw(10) << left << Client.PinCode;
//    cout << "| " << setw(40) << left << Client.Name;
//    cout << "| " << setw(12) << left << Client.Phone;
//    cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//void ShowAllClientsScreen()
//{
//    vector <stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//
//    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(10) << "Pin Code";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(12) << "Phone";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//
//    else
//    {
//        for (stClient &Client : vClients)
//        {
//            PrintClientRecordLine(Client);
//            cout << endl;
//        }
//    }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//}
//
//bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
//{
//    for (stClient C : vClients)
//    {
//
//        if (C.AccountNumber == AccountNumber)
//        {
//            Client = C;
//            return true;
//        }
//
//    }
//    return false;
//}
//
//bool ClientExistsByAccountNumber(string FileName, string AccountNumber)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line;
//        stClient Client;
//
//        while (getline(MyFile, Line))
//        {
//            Client = ConvertLinetoClientRecord(Line);
//            if (Client.AccountNumber == AccountNumber)
//            {
//                MyFile.close();
//                return true;
//            }
//        }
//
//        MyFile.close();
//    }
//
//    return false;
//}
//
//stClient ReadNewClient()
//{
//    stClient Client;
//
//    cout << "\nEnter Account Number ? ";
//    getline(cin >> ws, Client.AccountNumber);
//
//    while (ClientExistsByAccountNumber(ClientsFileName, Client.AccountNumber))
//    {
//        cout << "\nClients With [" << Client.AccountNumber << "] already exists, Enter another Account Number ? ";
//        getline(cin >> ws, Client.AccountNumber);
//    }
//
//    cout << "Enter PIN Code ? ";
//    getline(cin >> ws, Client.PinCode);
//
//    cout << "Enter Name ? ";
//    getline(cin, Client.Name);
//
//    cout << "Enter Phone ? ";
//    getline(cin, Client.Phone);
//
//    cout << "Enter Account Balance ? ";
//    cin >> Client.AccountBalance;
//
//    return Client;
//}
//
//string ConvertClientRecordToLine(stClient Client, string Seperater = "#//#")
//{
//    string stClientRecord = "";
//
//    stClientRecord += Client.AccountNumber + Seperater;
//    stClientRecord += Client.PinCode + Seperater;
//    stClientRecord += Client.Name + Seperater;
//    stClientRecord += Client.Phone + Seperater;
//    stClientRecord += to_string(Client.AccountBalance);
//
//    return stClientRecord;
//}
//
//void AddDataLineToFile(string FileName, string stDataLine)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::out | ios::app);
//
//    if (MyFile.is_open())
//    {
//        MyFile << stDataLine << endl;
//
//        MyFile.close();
//    }
//}
//
//void AddNewClient()
//{
//    stClient Client;
//    Client = ReadNewClient();
//    AddDataLineToFile(ClientsFileName, ConvertClientRecordToLine(Client));
//}
//
//void AddNewClients()
//{
//    char Answer = 'n';
//
//    do
//    {
//        cout << "Adding New Client : \n";
//
//        AddNewClient();
//
//        cout << "\nClient Add Syccessfully, do you want to add more clients ? Y/N ? ";
//        cin >> Answer;
//
//    } while (Answer == 'Y' || Answer == 'y');
//}
//
//void ShowAddNewClientsScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\tAdd New Clients Screen ";
//    cout << "\n-------------------------------------\n";
//
//    AddNewClients();
//}
//
//string ReadClientAccountNumber()
//{
//    string AccountNumber = "";
//
//    cout << "\nPlease enter Accout Number ? ";
//    cin >> AccountNumber;
//
//    return AccountNumber;
//}
//
//void PrintClientCard(stClient Client)
//{
//    cout << "\n\nThe following are the client details : \n";
//    cout << "---------------------------------------\n";
//    cout << "\nAccount Number : " << Client.AccountNumber;
//    cout << "\nPin Code       : " << Client.PinCode;
//    cout << "\nName           : " << Client.Name;
//    cout << "\nPhone          : " << Client.Phone;
//    cout << "\nAccount Balance : " << Client.AccountBalance;
//    cout << "\n---------------------------------------\n";
//
//}
//
//bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
//{
//
//    for (stClient& C : vClients)
//    {
//
//        if (C.AccountNumber == AccountNumber)
//        {
//            C.MarkForDelete = true;
//            return true;
//        }
//
//    }
//
//    return false;
//}
//
//vector <stClient> SaveCleintsDataToFile(string FileName, vector <stClient>& vClients)
//{
//    fstream MyFile;
//    MyFile.open(FileName, ios::out);//overwrite
//
//    string DataLine;
//
//    if (MyFile.is_open())
//    {
//        for (stClient C : vClients)
//        {
//
//            if (C.MarkForDelete == false)
//            {
//                //we only write records that are not marked for delete.  
//                DataLine = ConvertClientRecordToLine(C);
//                MyFile << DataLine << endl;
//            }
//
//        }
//
//        MyFile.close();
//    }
//
//    return vClients;
//}
//
//bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
//{
//    stClient Client;
//    char Answer = 'n';
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//
//        cout << "\n\nAre you sure you want delete this client? y/n ? ";
//        cin >> Answer;
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
//            SaveCleintsDataToFile(ClientsFileName, vClients);
//
//            //Refresh Clients 
//            vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//
//            cout << "\n\nClient Deleted Successfully.";
//            return true;
//        }
//
//    }
//    else
//    {
//        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
//        return false;
//    }
//}
//
//void ShowDeleteClientScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\tDelete Client Screen ";
//    cout << "\n-------------------------------------\n";
//
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//    DeleteClientByAccountNumber(AccountNumber, vClients);
//
//}
//
//stClient ChangeClientRecord(string AccountNumber)
//{
//    stClient Client;
//
//    Client.AccountNumber = AccountNumber;
//
//    cout << "\n\nEnter PIN Code ? ";
//    getline(cin >> ws, Client.PinCode);
//
//    cout << "Enter Name ? ";
//    getline(cin, Client.Name);
//
//    cout << "Enter Phone ? ";
//    getline(cin, Client.Phone);
//
//    cout << "Enter Account Balance ? ";
//    cin >> Client.AccountBalance;
//
//    return Client;
//}
//
//bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
//{
//    stClient Client;
//    char Answer = 'n';
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//
//        PrintClientCard(Client);
//
//        cout << "\n\nAre you sure you want Update this client? y/n ? ";
//        cin >> Answer;
//
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            for (stClient& C : vClients)
//            {
//                if (C.AccountNumber == AccountNumber)
//                {
//                    C = ChangeClientRecord(AccountNumber);
//                    break;
//                }
//            }
//
//            SaveCleintsDataToFile(ClientsFileName, vClients);
//
//
//            cout << "\n\nClient Update Successfully.";
//            return true;
//        }
//
//    }
//    else
//    {
//        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
//        return false;
//    }
//}
//
//void ShowUpdateClientScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\nUpdate Client Info Screen ";
//    cout << "\n-------------------------------------\n";
//
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//    UpdateClientByAccountNumber(AccountNumber, vClients);
//}
//
//void ShowFindClientScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\tFind Client Screen ";
//    cout << "\n-------------------------------------\n";
//
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//
//    stClient Client;
//
//    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        PrintClientCard(Client);
//    }
//
//    else
//    {
//        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
//    }
//
//}
//
//bool DepositBalanceToClientByAccoutnNumber(string AccountNumber, vector<stClient>& vClients, double AmountOfChange)
//{
//    char Answer = 'n';
//
//    cout << "\n\nAre you sure you want perform this transactions ? Y/N ?  ";
//    cin >> Answer;
//
//    if (Answer == 'Y' || Answer == 'y')
//    {
//        for (stClient& C : vClients)
//        {
//            if (C.AccountNumber == AccountNumber)
//            {
//                C.AccountBalance += AmountOfChange;
//                SaveCleintsDataToFile(ClientsFileName, vClients);
//                cout << "\n\nDone Successfully, New Balance is " << C.AccountBalance;
//                return true;
//            }
//        }
//
//        return false;
//    }
//}
//
//void ShowDepositScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\tDeposit Screen ";
//    cout << "\n-------------------------------------\n";
//
//    stClient Client;
//
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//
//    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        cout << "\nClient With [" << AccountNumber << "] does not exist.\n";
//
//        AccountNumber = ReadClientAccountNumber();
//    }
//
//
//    PrintClientCard(Client);
//
//    double Amount = 0;
//
//    cout << "\nPlease enter deposit amount ? ";
//    cin >> Amount;
//
//    DepositBalanceToClientByAccoutnNumber(AccountNumber, vClients, Amount);
//
//}
//
//void ShowWithdrawScreen()
//{
//    cout << "\n-------------------------------------\n";
//    cout << "\tWithdraw Screen ";
//    cout << "\n-------------------------------------\n";
//
//    stClient Client;
//
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//    string AccountNumber = ReadClientAccountNumber();
//
//    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
//    {
//        cout << "\nClient With [" << AccountNumber << "] does not exist.\n";
//
//        AccountNumber = ReadClientAccountNumber();
//    }
//
//
//    PrintClientCard(Client);
//
//    double Amount = 0;
//
//    cout << "\nPlease enter Withdraw amount ? ";
//    cin >> Amount;
//
//    //Validate That the amount does not esceeds the balance
//    while (Amount > Client.AccountBalance)
//    {
//        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance;
//
//        cout << "\nPlease enter Withdraw amount ? ";
//        cin >> Amount;
//    }
//
//    DepositBalanceToClientByAccoutnNumber(AccountNumber, vClients, (-1) * Amount);
//}
//
//void PrintClientRecordBalanceLine(stClient Client)
//{
//    cout << "| " << setw(15) << left << Client.AccountNumber;
//    cout << "| " << setw(40) << left << Client.Name;
//    cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//
//void ShowTotalBalances()
//{
//    vector<stClient> vClients = LoadCleintsDataFromFileToVector(ClientsFileName);
//
//    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "| " << left << setw(15) << "Accout Number";
//    cout << "| " << left << setw(40) << "Client Name";
//    cout << "| " << left << setw(12) << "Balance";
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    double TotalBalances = 0;
//
//    if (vClients.size() == 0)
//        cout << "\t\t\t\tNo Clients Available In the System!";
//
//    else
//    {
//        for (stClient& Client : vClients)
//        {
//            PrintClientRecordBalanceLine(Client);
//            TotalBalances += Client.AccountBalance;
//
//            cout << endl;
//        }
//    }
//
//    cout << "\n_______________________________________________________";
//    cout << "_________________________________________\n" << endl;
//
//    cout << "\t\t\t\t\tTotal Balances = " << TotalBalances;
//}
//
//void ShowTotalBalancesScreen()
//{
//    ShowTotalBalances();
//}
//
//enum enTransactionsMenueOption
//{
//    eDeposit = 1, eWithdraw = 2,
//    eShowTotalBalance = 3, eShowMainMenue = 4
//};
//
//void GoBackToTransactiosMenue(stUser CurrentUser)
//{
//    cout << "\n\nPress any key to go back to Transactions Menue...";
//    system("pause>0");
//    ShowTransactionsMenue(CurrentUser);
//}
//
//void PerformTransactionsMenueChoice(stUser CurrentUser,enTransactionsMenueOption TransactionsMenueOption)
//{
//    switch (TransactionsMenueOption)
//    {
//
//    case enTransactionsMenueOption::eDeposit:
//    {
//        system("cls");
//        ShowDepositScreen();
//        GoBackToTransactiosMenue(CurrentUser);
//        break;
//    }
//
//    case enTransactionsMenueOption::eWithdraw:
//    {
//        system("cls");
//        ShowWithdrawScreen();
//        GoBackToTransactiosMenue(CurrentUser);
//        break;
//    }
//
//    case enTransactionsMenueOption::eShowTotalBalance:
//    {
//        system("cls");
//        ShowTotalBalancesScreen();
//        GoBackToTransactiosMenue(CurrentUser);
//        break;
//    }
//
//    case enTransactionsMenueOption::eShowMainMenue:
//    {
//        ShowMainMenue(CurrentUser);
//        break;
//    }
//
//    }
//}
//
//short ReadTransactionsMenueOption()
//{
//    short Choice = 0;
//
//    cout << "Choose what do you want to do? [1 to 4]? ";
//    cin >> Choice;
//
//    return Choice;
//}
//
//void ShowTransactionsMenue(stUser CurrentUser)
//{
//    system("cls");
//    cout << "===========================================\n";
//    cout << "\t\tTransactions Menue Screen\n";
//    cout << "===========================================\n";
//    cout << "\t[1] Deposit.\n";
//    cout << "\t[2] Withdraw.\n";
//    cout << "\t[3] Total Balance.\n";
//    cout << "\t[4] Main Menue.\n";
//    cout << "===========================================\n";
//
//    PerformTransactionsMenueChoice(CurrentUser,(enTransactionsMenueOption)ReadTransactionsMenueOption());
//}
//
//vector<stUser> LoadUsersDataFromFileToVector(string FileName, string Seperater = "#//#")
//{
//    vector<stUser> vUsers;
//
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);
//
//    if (MyFile.is_open())
//    {
//        string Line = "";
//        stUser User;
//
//        while (getline(MyFile, Line))
//        {
//            User = ConvertLineToUserRecord(Line);
//            vUsers.push_back(User);
//        }
//
//        MyFile.close();
//
//    }
//
//
//    return vUsers;
//}
//
//void PrintUsersRecord(stUser User)
//{
//    cout << "| " << left << setw(15) << User.Username;
//    cout << "| " << left << setw(12) << User.Password;
//    cout << "| " << left << setw(40) << User.Permissions;
//}
//
//void ShowAllUsersScreen()
//{
//    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");
//
//    cout << "\n\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
//    cout << "\n_______________________________________________________________________________________\n\n";
//    cout << "| " << left << setw(15) << "User Name";
//    cout << "| " << left << setw(12) << "PassWord";
//    cout << "| " << left << setw(40) << "Permissions";
//    cout << "\n_______________________________________________________________________________________\n\n";
//
//    for (stUser& User : vUsers)
//    {
//        PrintUsersRecord(User);
//        cout << endl;
//    }
//
//    cout << "\n_______________________________________________________________________________________\n\n";
//
//}
//
//enum enManageUsersOption
//{
//    eListUsers = 1, eAddNewUser = 2,
//    eDeleteUser = 3, eUpdateUser = 4,
//    eFindUser = 5, eMainMenue = 6
//};
//
//short ReadManageUsersChoice()
//{
//    short Choice = 0;
//
//    cout << "Choose What Do you want to do ? [1 to 6] ? ";
//    cin >> Choice;
//
//    return Choice;
//}
//
//void GoBackToManageUsersScreen(stUser CurrentUser)
//{
//    cout << "\n\nPress any key to go back to Manage Users...";
//    system("pause>0");
//    ShowManageUsersMenue(CurrentUser);
//}
//
//string ConvertUserRecordToLine(stUser User, string Delim = "#//#")
//{
//    string Line = "";
//
//    Line = User.Username + Delim;
//    Line += User.Password + Delim;
//    Line += to_string(User.Permissions);
//
//    return Line;
//}
//
//bool UserExistsByUsername(string Username,stUser &CurrentUser)
//{
//    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");
//
//    for (stUser User : vUsers)
//    {
//        if (User.Username == Username)
//        {
//            CurrentUser.Username = User.Username;
//            CurrentUser.Password = User.Password;
//            CurrentUser.Permissions = User.Permissions;
//            return true;
//        }
//    }
//    return false;
//}
//
//short ReadPermissionsToSet()
//{
//    short Permissions = 0;
//
//    char Approve = 'y';
//    cout << "\nDo You want to give full access ? Y/N ? ";
//    cin >> Approve;
//
//    if (toupper(Approve) == 'Y')
//        return -1;
//
//
//    cout << "\n\nDo you want to give access to : ";
//       
//
//    cout << "\n\nShow Client List ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 1;
//
//
//    cout << "\nAdd New Client ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 2;
//
//    cout << "\nDelete Client ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 4;
//
//    cout << "\nUpdate Client ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 8;
//
//    cout << "\nFind Client ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 16;
//
//    cout << "\nTransactions ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 32;
//
//    cout << "\nManage Users ? Y/N ? ";
//    cin >> Approve;
//    if (toupper(Approve) == 'Y')
//        Permissions += 64;
//
//
//    return Permissions;
//}
//
//stUser ReadNewUser()
//{
//    stUser NewUser;
//
//    cout << "\nAdding New User : \n\n";
//
//    cout << "Enter Username ? ";
//    getline(cin >> ws, NewUser.Username);
//
//    while (UserExistsByUsername(NewUser.Username, NewUser))
//    {
//        cout << "\nUser With [" << NewUser.Username << "] already exists, Enter another username ? ";
//        getline(cin >> ws, NewUser.Username);
//    }
//
//    cout << "Enter Password ? ";
//    getline(cin, NewUser.Password);
//
//    NewUser.Permissions = ReadPermissionsToSet();
//
//    return NewUser;
//}
//
//bool AddNewUser(string FileName, stUser NewUser)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::out | ios::app);
//
//    if (MyFile.is_open())
//    {
//        string Line = ConvertUserRecordToLine(NewUser);
//
//        MyFile << Line << endl;
//
//        MyFile.close();
//        return true;
//    }
//
//    return false;
//}
//
//void AddNewUsers()
//{
//    char AddMore = 'N';
//
//    do
//    {
//        stUser NewUser = ReadNewUser();
//
//        AddNewUser(UsersFileName, NewUser);
//
//        cout << "\nUser Add Successfully, Do you want to add more users ? Y/N ? ";
//        cin >> AddMore;
//
//    } while (toupper(AddMore) == 'Y');
//}
//
//void ShowAddNewUsersScreen()
//{
//    cout << "\n----------------------------------------\n";
//    cout << "\tAdd New User Screen.";
//    cout << "\n----------------------------------------";
//
//    AddNewUsers();
//}
//
//void PrintUserCard(stUser User)
//{
//    cout << "\n\nThe following are the User details : \n";
//    cout << "---------------------------------------\n";
//    cout << "\nUsername    : " << User.Username;
//    cout << "\nPassword    : " << User.Password;
//    cout << "\nPermissions : " << User.Permissions;
//    cout << "\n---------------------------------------\n";
//}
//
//bool MarkUserForDeleteByUsername(string Username, vector<stUser>& vUsers)
//{
//    for (stUser& User : vUsers)
//    {
//        if (User.Username == Username)
//        {
//            User.MarkForDelete = true;
//            return true;
//        }
//    }
//
//    return false;
//}
//
//vector<stUser>SaveUsersDataToFile(string FileName, vector<stUser>& vUsers)
//{
//    fstream MyFile;
//    MyFile.open(FileName, ios::out);//overwrite
//
//    string DataLine;
//
//    if (MyFile.is_open())
//    {
//        for (stUser U : vUsers)
//        {
//
//            if (U.MarkForDelete == false)
//            {
//                //we only write records that are not marked for delete.  
//                DataLine = ConvertUserRecordToLine(U);
//                MyFile << DataLine << endl;
//            }
//
//        }
//
//        MyFile.close();
//    }
//
//    return vUsers;
//}
//
//bool DeleteUserByUsername(string Username, vector<stUser>& vUsers)
//{
//    stUser User;
//    char Answer = 'n';
//
//    if (Username == "Admin")
//    {
//        cout << "\n\nYou Can not Delete This User.";
//        return false;
//    }
//
//    if (UserExistsByUsername(Username, User))
//    {
//        PrintUserCard(User);
//
//        cout << "\n\nAre you sure you want delete this User? y/n ? ";
//        cin >> Answer;
//
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            MarkUserForDeleteByUsername(User.Username, vUsers);
//            SaveUsersDataToFile(UsersFileName, vUsers);
//
//            //Refresh Clients 
//            vUsers = LoadUsersDataFromFileToVector(UsersFileName);
//
//            cout << "\n\nUsert Deleted Successfully.";
//            return true;
//        }
//
//    }
//    else
//    {
//        cout << "\nUser with Username (" << Username << ") is Not Found!";
//        return false;
//    }
//
//}
//
//void showDeleteUserScreen()
//{
//    cout << "\n----------------------------------------\n";
//    cout << "\tDelete User Screen.";
//    cout << "\n----------------------------------------";
//   
//    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");
//    
//    string Username;
//    cout << "\nEnter Username ? ";
//    getline(cin >> ws, Username);
//   
//    DeleteUserByUsername(Username, vUsers);
//
//}
//
//stUser ChangeUserRecord(string Username)
//{
//    stUser User;
//
//    User.Username = Username;
//
//    cout << "\n\nEnter Password ? ";
//    getline(cin >> ws, User.Password);
//
//    User.Permissions = ReadPermissionsToSet();
//
//    return User;
//}
//
//bool UpdateUserByUsername(string Username, vector<stUser>& vUsers)
//{
//    stUser User;
//    char Answer = 'n';
//
//    if (UserExistsByUsername(Username, User))
//    {
//        PrintUserCard(User);
//
//        cout << "\n\nAre you sure you want Update this User? Y/N ? ";
//        cin >> Answer;
//
//        if (Answer == 'y' || Answer == 'Y')
//        {
//            for (stUser& U : vUsers)
//            {
//                if (U.Username == Username)
//                {
//                    U = ChangeUserRecord(Username);
//                    break;
//                }
//            }
//
//            SaveUsersDataToFile(UsersFileName, vUsers);
//
//
//            cout << "\n\nUser Update Successfully.";
//            return true;
//        }
//    }
//    else
//    {
//        cout << "\nUser with Username (" << Username << ") is Not Found!";
//        return false;
//    }
//
//}
//
//void ShowUpdateUserScreen()
//{
//    cout << "\n----------------------------------------\n";
//    cout << "\tUpdate User Screen.";
//    cout << "\n----------------------------------------";
//
//    vector<stUser>vUsers = LoadUsersDataFromFileToVector(UsersFileName, "#//#");
//
//    string Username;
//    cout << "\nEnter Username ? ";
//    getline(cin >> ws, Username);
//
//    UpdateUserByUsername(Username, vUsers);
//}
//
//void ShowFindUserScreen()
//{
//    cout << "\n----------------------------------------\n";
//    cout << "\tFind User Screen.";
//    cout << "\n----------------------------------------";
//
//    string Username;
//    stUser User;
//
//    cout << "\nPlease Enter Username ? ";
//    getline(cin >> ws, Username);
//
//    if (UserExistsByUsername(Username, User))
//    {
//        PrintUserCard(User);
//    }
//    else
//    {
//        cout << "\nUser with Username (" << Username << ") is Not Found!\n";
//    }
//}
//
//void PerformManageUsersMenueChoice(stUser CurrentUser,enManageUsersOption ManageUsersOption)
//{
//    switch (ManageUsersOption)
//    {
//    case enManageUsersOption::eListUsers:
//    {
//        system("cls");
//        ShowAllUsersScreen();
//        GoBackToManageUsersScreen(CurrentUser);
//        break;   
//    }
//
//    case enManageUsersOption::eAddNewUser:
//    {
//        system("cls");
//        ShowAddNewUsersScreen();
//        GoBackToManageUsersScreen(CurrentUser);
//    }
//
//    case enManageUsersOption::eDeleteUser:
//    {
//        system("cls");
//        showDeleteUserScreen();
//        GoBackToManageUsersScreen(CurrentUser);
//    }
//
//    case enManageUsersOption::eUpdateUser:
//    {
//        system("cls");
//        ShowUpdateUserScreen();
//        GoBackToManageUsersScreen(CurrentUser);
//    }
//
//    case enManageUsersOption::eFindUser:
//    {
//        system("cls");
//        ShowFindUserScreen();
//        GoBackToManageUsersScreen(CurrentUser);
//    }
//
//    case enManageUsersOption::eMainMenue:
//    {
//        ShowMainMenue(CurrentUser);
//    }
//    default:
//        ShowMainMenue(CurrentUser);
//
//    }
//}
//
//void ShowManageUsersMenue(stUser CurrentUser)
//{
//    system("cls");
//    cout << "==================================================\n";
//    cout << "\t\tManage Users Menue Screen.\n";
//    cout << "==================================================\n";
//    cout << "\t[1] List Users.\n";
//    cout << "\t[2] Add New User.\n";
//    cout << "\t[3] Delete User.\n";
//    cout << "\t[4] Update User.\n";
//    cout << "\t[5] Find User.\n";
//    cout << "\t[6] Main Menue.\n";
//    cout << "==================================================\n";
//
//    PerformManageUsersMenueChoice(CurrentUser,(enManageUsersOption)ReadManageUsersChoice());
//}
//
//enum enMainMenueOption
//{
//    eListClients = 1, eAddNewClient = 2,
//    eDeleteClient = 3, eUpdateClient = 4,
//    eFindClient = 5, eShowTransactionsMenue = 6,
//    eMangeUsers = 7, eExit = 8
//};
//
//void GoBackToMainMenue(stUser CurrentUser)
//{
//    cout << "\n\nPress any key to go back to Main Menue...";
//    system("pause>0");
//    ShowMainMenue(CurrentUser);
//}
//
//void AccessDeniedMessage(stUser CurrentUser)
//{
//    system("cls");
//    cout << "\n-------------------------------------\n";
//    cout << "Access Denied, \n";
//    cout << "You don't Have Permission To Do this, \n";
//    cout << "Please conact Your Admin.";
//    cout << "\n-------------------------------------\n";
//
//    GoBackToMainMenue(CurrentUser);
//}
//
//void PerformMainMenueChoice(stUser CurrentUser,enMainMenueOption MainMenueOption)
//{
//    switch (MainMenueOption)
//    {
//
//    case enMainMenueOption::eListClients:
//    {
//        system("cls");
//        ShowAllClientsScreen();
//        GoBackToMainMenue(CurrentUser);
//        break;
//    }
//        
//       
//
//    case enMainMenueOption::eAddNewClient:
//    {
//        system("cls");
//        ShowAddNewClientsScreen();
//        GoBackToMainMenue(CurrentUser);
//        break;
//    }
//
//    case enMainMenueOption::eDeleteClient:
//    {
//        system("cls");
//        ShowDeleteClientScreen();
//        GoBackToMainMenue(CurrentUser);
//        break;
//    }
//        
//       
//    case enMainMenueOption::eUpdateClient:
//    {
//        system("cls");
//        ShowUpdateClientScreen();
//        GoBackToMainMenue(CurrentUser);
//        break;
//    }
//       
//    case enMainMenueOption::eFindClient:
//    {
//        system("cls");
//        ShowFindClientScreen();
//        GoBackToMainMenue(CurrentUser);
//        break;
//    }
//       
//    case enMainMenueOption::eShowTransactionsMenue:
//    {
//        ShowTransactionsMenue(CurrentUser);
//        break;
//    }
//  
//    case enMainMenueOption::eMangeUsers:
//    {
//        ShowManageUsersMenue(CurrentUser);
//        break;
//    }
//
//    case enMainMenueOption::eExit:
//    {
//        system("cls");
//        Login();
//        break;
//    }
//
//    }
//}
//
//short ReadMainMenueOption()
//{
//    short Choice = 0;
//
//    cout << "Choose what do you want to do? [1 to 8]? ";
//    cin >> Choice;
//
//    return Choice;
//}
//
//bool CheckAccessPermission(stUser CurrentUser, short ChoiceNumber)
//{
//    short BinaryChoiceNumber = pow(2, ChoiceNumber - 1);
//
//    return (((CurrentUser.Permissions & BinaryChoiceNumber) == BinaryChoiceNumber) || ChoiceNumber == 8);
//}
//
//void ShowMainMenue(stUser CurrentUser)
//{
//    system("cls");
//    cout << "===========================================\n";
//    cout << "\t\tMain Menue Screen\n";
//    cout << "===========================================\n";
//    cout << "\t[1] Show Client List.\n";
//    cout << "\t[2] Add New Client.\n";
//    cout << "\t[3] Delete Client.\n";
//    cout << "\t[4] Update Client Info.\n";
//    cout << "\t[5] Find Client.\n";
//    cout << "\t[6] Transactions.\n";
//    cout << "\t[7] Manage Users.\n";
//    cout << "\t[8] Logout.\n";
//    cout << "===========================================\n";
//
//    short ChoiceNumber = ReadMainMenueOption();
//
//
//
//    if (CheckAccessPermission(CurrentUser,ChoiceNumber))
//    {
//        PerformMainMenueChoice(CurrentUser, (enMainMenueOption)ChoiceNumber);
//    }
//
//    else
//    {
//        AccessDeniedMessage(CurrentUser);
//    }
//
//}
//
//void Login()
//{
//    ShowLoginScreen();
//
//    ShowMainMenue(ReadLoginInfo());
//}
//
//int main()
//{
//    Login();
//
//    system("pause>0");
//    return 0;
//}