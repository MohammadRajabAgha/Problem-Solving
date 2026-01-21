#include <iostream>
#include<string>
#include<cctype>

using namespace std;

string ReadString(string Message)
{
    string Text;

    cout << Message;

    getline(cin, Text);

    return Text;
}

char ReadChar(string Message)
{
    char Character;

    cout << Message;

    cin >> Character;

    return Character;
}

char InvertLetterCase(char Character)
{
    return (isupper(Character) ? tolower(Character) : toupper(Character));
}

short CountLetter(string Text, char Letter,bool IsMatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < Text.length(); i++)
    {
        if (IsMatchCase)
        {
            if (Text[i] == Letter)
                Counter++;
        }

        else
        {
            if (tolower(Text[i]) == tolower(Letter))
                Counter++;
        }
    }

    return Counter;

}

int main()
{
    string Text = ReadString("Please Enter Your String ? \n");

    char Character = ReadChar("\nPlease Enter a Character ? \n");

    cout << "\nLetter \'" << Character << "\' Count = "
        << CountLetter(Text, Character) << endl;

    cout << "\nLetter \'" << Character 
         << "\' or \'"<< InvertLetterCase(Character) << "\' "
         << " Count = " << CountLetter(Text, Character, false) << endl;


    system("pause>0");
}