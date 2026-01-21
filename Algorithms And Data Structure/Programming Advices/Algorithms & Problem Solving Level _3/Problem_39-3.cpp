#include<iostream>
#include<string>
#include<vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
    string Text;

    for (string& S : vString)
    {
        Text = Text + S + Delim;
    }

    return Text.substr(0, Text.length() - Delim.length());
}

//string JoinString(vector<string> vString, string Delim)
//{
//    string Text;
//
//    for (auto iter = vString.begin(); iter != vString.end(); iter++)
//    {
//        Text = Text + *iter;
//
//        if (iter != vString.end() - 1)
//        {
//            Text = Text + Delim;
//        }
//    }
//
//    return Text;
//}

int main()
{
    
    vector <string> vString = { "Mohammad","Fadi","Ali","Maher" };

    cout << "Vector After Join : \n";
    cout << JoinString(vString, "####");

    system("pause>0");
}