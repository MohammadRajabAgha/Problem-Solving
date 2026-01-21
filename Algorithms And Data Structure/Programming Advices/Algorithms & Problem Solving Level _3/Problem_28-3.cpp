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

char InvertLetterCase(char Character)
{
    return (isupper(Character) ? tolower(Character) : toupper(Character));
}

string InvertAllStringLettersCase(string Text)
{
    for (short i = 0; i < Text.length(); i++)
    {
        Text[i] = InvertLetterCase(Text[i]);
    }
 
    return Text;

}

int main()
{
    string Text;

    Text = ReadString("Please Enter Your String ? \n");

    cout << "String after inverting All Letters case : \n";
    cout << InvertAllStringLettersCase(Text) << "\n\n";



    system("pause>0");
}