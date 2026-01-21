#include <iostream>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
using namespace std;

string ReadText(string Message)
{
    string Text;

    cout << Message;
    
    getline(cin, Text);

    return Text;
}


//void PrintFirstLetterOfEachWord(string Text)
//{
//    cout << "\nFirst Letters Of This String : \n";
//
//    cout << Text[0] << "\n";
//
//    for (short i = 0; i < Text.length(); i++)
//    {
//        if (Text[i] == ' ')
//        {
//            cout << Text[i + 1] << "\n";
//        }
//    }
//}

void PrintFirstLetterOfEachWord(string Text)
{
    bool isFirstLetter = true;

    cout << "\nFirst Letters Of This String : \n";

    for (short i = 0; i < Text.length(); i++)
    {
        if (Text[i] != ' ' && isFirstLetter)
        {
            cout << Text[i] << "\n";
        }

        isFirstLetter = (Text[i] == ' ' ? true : false);
    }

}

int main()
{

    PrintFirstLetterOfEachWord(ReadText("Pleas ente Your String ? \n"));

    system("pause>0");
}
