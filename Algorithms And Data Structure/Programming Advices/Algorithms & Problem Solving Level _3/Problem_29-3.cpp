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

enum enWhatToCount { CapitalLetters, SmallLetters, Digit, Puctuation, AllLetters };

short CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::AllLetters) //Default Parameters
{
    short Count = 0;

    for (short i = 0; i < Text.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && (isupper(Text[i])))
            Count++;

        if (WhatToCount == enWhatToCount::SmallLetters && (islower(Text[i])))
            Count++;

        if (WhatToCount == enWhatToCount::Digit && (isdigit(Text[i])))
            Count++;

        if (WhatToCount == enWhatToCount::Puctuation && (ispunct(Text[i])))
            Count++;

        if (WhatToCount == enWhatToCount::AllLetters && (Text[i] != ' '))
            Count++;
    }

    return Count;

}

short CountCapitalLetters(string Text)
{
    short Count = 0;

    for (short i = 0; i < Text.length(); i++)
    {
        if (isupper(Text[i]))
        {
            Count++;
        }
    }

    return Count;

}

short CountSmallLetters(string Text)
{
    short Count = 0;

    for (short i = 0; i < Text.length(); i++)
    {
        if (islower(Text[i]))
        {
            Count++;
        }
    }

    return Count;

}

int main()
{
    string Text;

    Text = ReadString("Please Enter Your String ? \n");

    cout << "\n\nMethod 1 : \n";

    cout << "\nString Length = " << Text.length();
    cout << "\nCapital Letters Count = " << CountCapitalLetters(Text);
    cout << "\nSmall Letters Count = " << CountSmallLetters(Text);

    cout << "\n\nMethod 2 : \n";

    cout << "\nString Length = " << Text.length();
    cout << "\nAll Letters Count = " << CountLetters(Text, enWhatToCount::AllLetters);
    cout << "\nCapital Letters Count = " << CountLetters(Text, enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count = " << CountLetters(Text, enWhatToCount::SmallLetters);
    cout << "\nDigit Count = " << CountLetters(Text, enWhatToCount::Digit);
    cout << "\nPunctuation Count = " << CountLetters(Text, enWhatToCount::Puctuation);

    system("pause>0");
}