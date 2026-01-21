#include<iostream>
#include<string>
#include<vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
    string Text = "";

    for (string& S : vString)
    {
        Text = Text + S + Delim;
    }

    return Text.substr(0, Text.length() - Delim.length());
}

//Over Loading...

string JoinString(string arrString[], short arrLength, string Delim)
{
    string Text = "";

    for (short i = 0; i < arrLength; i++)
    {
        Text = Text + arrString[i] + Delim;
    }

    return Text.substr(0, Text.length() - Delim.length());
}

int main()
{

    vector <string> vString = { "Mohammad","Fadi","Ali","Maher" };
    string arrString[] = { "Mohammad","Fadi","Ali","Maher" };

    cout << "Vector After Join : \n";
    cout << JoinString(vString, "####");

    cout << "\n\nArray After Join : \n";
    cout << JoinString(arrString, 4, "####");

    

    system("pause>0");
}