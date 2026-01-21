#include <iostream> 
#include<string>
#include<cctype> 

using namespace std;

string ReadText(const string& Message)
{
    string Text;

    cout << Message;

    getline(cin, Text);

    return Text;

}

bool IsVowel(char Letter)
{
    Letter = tolower(Letter);

    return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));

}

void PrintAllVowelsInString(string Text)
{
    cout << "\nVowels in String are = ";
    for (short i = 0; i < Text.length(); i++)
    {
        if (IsVowel(Text[i]))
            cout << Text[i] << "    ";
    }

    cout << endl;

}

int main()
{
    string Text = ReadText("Please Enter Your String ? \n");

    PrintAllVowelsInString(Text);


    system("pause>0");
}