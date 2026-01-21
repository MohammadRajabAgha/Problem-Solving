#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iomanip>
#include<fstream> //To Dealing With Files...

using namespace std;

//My Solution...

//#include <iostream>
//#include<vector>
//#include<string>
//#include<cctype>
//#include<iomanip>
//#include<fstream> //To Dealing With Files...
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
//};
//
//vector<string> SplitString(string Text, string Delim)
//{
//    vector <string> vString;
//
//    short Pos = 0;
//
//    // define a string variable 
//    string sWord;//....|| string Token;
//
//    // use find() function to get the position of the delimiter
//    while ((Pos = Text.find(Delim)) != std::string::npos)
//    {
//        sWord = Text.substr(0, Pos);// store the word
//
//        if (sWord != "")
//        {
//            vString.push_back(sWord);
//        }
//
//        Text.erase(0, Pos + Delim.length());/* erase() until positon and move to next word. */
//
//    }
//
//    if (Text != "")
//    {
//        vString.push_back(Text);// It adds last word of the string...
//    }
//
//    return vString;
//
//}
//
//sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
//{
//    sClient Client;
//    vector<string> vClientData;
//
//    vClientData = SplitString(Line, Seperator);
//
//    Client.AccountNumber = vClientData[0];
//    Client.PINCode = vClientData[1];
//    Client.Name = vClientData[2];
//    Client.Phone = vClientData[3];
//    Client.AccountBalance = stod(vClientData[4]);//Cast String To double...
//
//    return Client;
//}
//
//vector<sClient> LoadClientsDataFromFileToVector(string FileName)
//{
//    vector<sClient> vClient;
//
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);//Read Mode...
//
//    if (MyFile.is_open())
//    {
//        string Line;
//
//        sClient Client;
//
//        while (getline(MyFile, Line))
//        {
//
//            Client = ConvertLineToRecord(Line);
//
//            vClient.push_back(Client);
//        }
//
//
//        MyFile.close();
//
//    }
//
//    return vClient;
//
//}
//
//string ReadText(string Message)
//{
//    string Text;
//
//    cout << Message;
//
//    cin >> Text;
//
//    return Text;
//}
//
//void PrintClientRecord(sClient Client)
//{
//    cout << "\n\nThe Following is The  Client details : \n";
//
//    cout << "\nAccount Number  : " << Client.AccountNumber;
//    cout << "\nPin Code        : " << Client.PINCode;
//    cout << "\nName            : " << Client.Name;
//    cout << "\nPhone           : " << Client.Phone;
//    cout << "\nAccount Balance : " << Client.AccountBalance;
//
//    cout << "\n\n";
//
//}
//
//sClient FindClientDataByAccountNumber(vector<sClient> vClients, string PerAccountNumber)
//{
//    for (sClient& Client : vClients)
//    {
//        if (Client.AccountNumber == PerAccountNumber)
//        {
//            return Client;
//        }
//    }
//
//    return sClient();
//}
//
//void PrintResult(vector <sClient> vClient, string PerAccountNumber)
//{
//    sClient Client;
//
//    Client = FindClientDataByAccountNumber(vClient, PerAccountNumber);
//
//    if (Client.AccountNumber != "")
//    {
//        PrintClientRecord(Client);
//    }
//
//    else
//    {
//        cout << "\nClient With Account Number (" << PerAccountNumber << ") Not Found ! \n\n";
//    }
//}
//
//int main()
//{
//    vector <sClient> vClient;
//
//    string PerAccountNumber;
//
//    PerAccountNumber = ReadText("Please enter Account Number ? ");
//
//    vClient = LoadClientsDataFromFileToVector(ClientsFileName);
//
//    PrintResult(vClient, PerAccountNumber);
//
//    system("pause>0");
//}
//
//
//	
//
//

//


const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PINCode;
    string Name;
    string Phone;
    double AccountBalance;
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

string ReadText(string Message)
{
    string Text;

    cout << Message;

    cin >> Text;

    return Text;
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

bool FindClientDataByAccountNumber(string AccountNumber,sClient &Client)
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

int main()
{
    sClient Client;

    string AccountNumber;

    AccountNumber = ReadText("Please enter Account Number ? ");

        if (FindClientDataByAccountNumber(AccountNumber, Client))
        {
            PrintClientCard(Client);
        }

        else
        {
            cout << "\nClient With Account Number (" << AccountNumber << ") Not Found ! \n\n";
        }
    

  

    system("pause>0");
}