#include <iostream>
#include<string>
#include<cctype>

using namespace std;

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

int main()
{
    char character;

    character = ReadChar("Please Enter a Character ? \n");

    cout << "Char after inverting case : \n";
    cout << InvertLetterCase(character) << "\n\n";
   


    system("pause>0");
}