#include <iostream>
#include<cctype>
#include<string>
using namespace std;

string ReadText(string Message)
{
    string Text;

    cout << Message;

    getline(cin, Text);

    return Text;
}

string UpperAllString(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = toupper(Text[i]);
    }

    return Text;
}

string LowerAllString(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = tolower(Text[i]);
    }

    return Text;
}

int main()
{
    string Text;

    Text = ReadText("Please enter Your String ? \n");

    Text = UpperAllString(Text);
    cout << "\nString After Upper : \n";
    cout << Text << "\n";


    Text = LowerAllString(Text);
    cout << "\nString After Lower : \n";
    cout << Text << "\n";


}

