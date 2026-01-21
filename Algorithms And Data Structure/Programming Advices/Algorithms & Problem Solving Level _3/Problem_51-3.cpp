#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iomanip>
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
    bool MarkForDelete = false;
};
vector<string> SplitString(string Text, string Delim)
{
    vector <string> vString;

    short Pos = 0;

    // define a string variable 
    string sWord;//....|| string Token;

    // use find() function to get the position of the delimiter
    while ((Pos = Text.find(Delim)) != std::string::npos)
    {
        sWord = Text.substr(0, Pos);// store the word

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        Text.erase(0, Pos + Delim.length());/* erase() until positon and move to next word. */

    }

    if (Text != "")
    {
        vString.push_back(Text);// It adds last word of the string...
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

void PrintClientCard(sClient Client)
{
    cout << "\n\nThe Following is The  Client details : \n";

    cout << "\nAccount Number  : " << Client.AccountNumber;
    cout << "\nPin Code        : " << Client.PINCode;
    cout << "\nName            : " << Client.Name;
    cout << "\nPhone           : " << Client.Phone;
    cout << "\nAccount Balance : " << Client.AccountBalance;

    cout << "\n\n";

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

string ReadText(string Message)
{
    string Text;

    cout << Message;

    cin >> Text;

    return Text;
}

int main()
{
    vector <sClient> vClients;

    vClients = LoadClientsDataFromFileToVector(ClientsFileName);

    string AccountNumber;

    AccountNumber = ReadText("Please enter Account Number ? ");

    UpdateClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
}