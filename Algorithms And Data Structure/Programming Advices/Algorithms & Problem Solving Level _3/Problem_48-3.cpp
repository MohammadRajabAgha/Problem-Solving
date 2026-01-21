#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<iomanip>
#include<fstream> //To Dealing With Files...

using namespace std;

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
//void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
//{
//    fstream MyFile;
//
//    MyFile.open(FileName, ios::in);//Read Mode...
//
//    if (MyFile.is_open())
//    {
//        string Line;
//
//        while (getline(MyFile, Line))
//        {
//            vFileContent.push_back(Line);
//        }
//
//        MyFile.close();
//    }
//}
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
//void PrintHeader(short NumberOfClients)
//{
//    cout << right << setw(55) << "Clients List (" << NumberOfClients << ") Client(s).\n";
//    cout << "_____________________________________________________________________________________________________\n\n";
//    cout << setw(17) << "| Account Number  " << setw(12) << "| Pin Code  " << left << setw(45) << "| Client Name " << setw(15) << "| Phone " << setw(11) << "| Balance \n";
//    cout << "_____________________________________________________________________________________________________\n\n";
//
//}
//
//void PrintClientRecord(sClient Client)
//{
//    cout << "| " << left << setw(16) << Client.AccountNumber;
//    cout << "| " << left << setw(10) << Client.PINCode;
//    cout << "| " << left << setw(43) << Client.Name;
//    cout << "| " << left << setw(13) << Client.Phone;
//    cout << "| " << left << setw(10) << Client.AccountBalance;
//
//    cout << "\n";
//}
//
//void PrintAllClients(vector <string> vFileContent)
//{
//    for (string& Line : vFileContent)
//    {
//        PrintClientRecord(ConvertLineToRecord(Line));
//    }
//}
//
//void PrintFooter()
//{
//    cout << "\n_____________________________________________________________________________________________________\n";
//}
//
//void ShowAllClients()
//{
//    vector <string> vFileContent;
//
//    LoadDataFromFileToVector(ClientsFileName, vFileContent);
//
//    PrintHeader(vFileContent.size());
//
//    PrintAllClients(vFileContent);
//
//    PrintFooter();
//}
//
//int main()
//{
//    ShowAllClients();
//
//    system("pause>0");
//}

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
    cout << setw(15) << "| Phone ";
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

int main()
{	
    vector <sClient> vClient;

    vClient = LoadClientsDataFromFileToVector(ClientsFileName);

    PrintClientsData(vClient);

	system("pause>0");
}




