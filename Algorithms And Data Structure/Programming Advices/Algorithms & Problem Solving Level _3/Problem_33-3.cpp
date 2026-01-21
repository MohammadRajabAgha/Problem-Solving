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

short CountVowels(string Text)
{ 
    short Counter = 0;

    for (short i = 0; i < Text.length(); i++)
    { 
        if (IsVowel(Text[i]))
            Counter++;
    } 
    
    return Counter;
} 

int main() 
{ 
    string Text = ReadText("Please Enter Your String ? \n");
    
    cout << "\nNumber Of Vowels is = " << CountVowels(Text) << endl; 
    
    system("pause>0"); 
}