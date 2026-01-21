#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadText(string Message)
{
    string Text = "";

    cout << Message;

    if (cin.peek() == '\n')
    {
        cin.ignore(1, '\n');
    }

    do
    {
        getline(cin, Text);

        if (Text.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
        }

    } while (Text.empty());

    return Text;

}

//string TrimLeftString(string Text)
//{
//    while (Text[0] == ' ')
//    {
//        Text.erase(0, 1);
//    }
//    
//    return Text;
//
//}
//
//string TrimRightString(string Text)
//{
//    while (Text[Text.length() - 1] == ' ')
//    {
//        Text.erase(Text.length() - 1, 1);
//    }
//
//    return Text;
//
//}
//
//string TrimString(string Text)
//{
//    Text = TrimLeftString(Text);
//    Text = TrimRightString(Text);
//
//    return Text;
//}

string TrimLeft(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ')
        {
            return Text.substr(i, Text.length() - i);
        }
    }

    return "";
}

string TrimRight(string Text)
{
    for (short i = Text.length(); i > 0; i--)
    {
        if (Text[i] != ' ')
        {
            return Text.substr(0, i + 1);
        }
    }

    return "";
}

string Trim(string Text)
{
    return TrimLeft(TrimRight(Text));
}


int main()
{
    string Text;
   
    Text = ReadText("Please Enter Your String : ");

    //Text = "          Mohammad Agha          ";

    cout << "\nString    = " << Text << endl;
    cout << "\nTrim Left = " << TrimLeft(Text);
    cout << "\nTrimRight = " << TrimRight(Text);
    cout << "\nTrim      = " << Trim(Text);

    system("pause>0");
}