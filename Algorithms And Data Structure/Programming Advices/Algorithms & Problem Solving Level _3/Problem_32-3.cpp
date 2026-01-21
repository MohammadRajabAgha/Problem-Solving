#include <iostream> 
#include<string>
#include<cctype> 

using namespace std; 

char ReadChar(const string& Message)
{
    char Character; 

    cout << Message;

    cin >> Character;

    return Character;
} 

bool IsVowel(char Letter) 
{
    Letter = tolower(Letter);

    return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));

} 

int main() 
{
    char Character = ReadChar("Please Enter a Character ? \n"); 

    if (IsVowel(Character))
    {
        cout << "\nYes Letter \'" << Character << "\' is Vowel.\n";
    }

    else
    {
        cout << "\nNo Letter \'" << Character << "\' is NOT Vowel.\n";
    }


system("pause>0"); }