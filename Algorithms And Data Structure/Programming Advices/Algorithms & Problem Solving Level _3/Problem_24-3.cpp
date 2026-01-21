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


string UpperFirstLetterOfEachWord(string Text)
{
    bool isFirstLetter = true;

    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && isFirstLetter)
        {
            Text[i] = toupper(Text[i]);
        }
    
        isFirstLetter = (Text[i] == ' ' ? true : false);
        //isFirstLetter = ((Text[i] == ' ') || (ispunct(Text[i])) ? true : false); //Mohammad Abu-Hadhoud
    }

    return Text;

    /* string UpperFirstLetterOfEachWord(string Text)
        {
            bool isFirstLetter = true;

            for (short i = 0; i < Text.length(); i++)
            {
                if (Text[i] != ' ' && isFirstLetter)
                {
                    Text[i] = toupper(Text[i]);
                }

                isFirstLetter = ((Text[i] == ' ') || (ispunct(Text[i])) ? true : false);

            }

            return Text;

        }*/

}

int main()
{
    string Text;

    Text = ReadText("Please enter Your String ? \n");

    Text = UpperFirstLetterOfEachWord(Text);

    cout << "\nString After Conversion : \n";
    cout << Text << "\n";

}

