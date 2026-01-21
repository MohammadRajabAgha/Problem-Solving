#pragma once

#pragma warning(disable : 4996)

#include "NumberManipulater.h"
#include<iostream>
#include <cstdlib>
#include<vector>

using namespace std;

namespace StringManipulation
{
    bool Login(string PinCode)
    {
        //the PINCode you should by string...

        string CorrectPIN = "1234";

        do
        {
            if (PinCode == CorrectPIN)
            {
                return true;
            }

            else
            {
                cout << "\nWrong PIN \n";
                system("color 4F");
            }

        } while (PinCode != CorrectPIN);

    }

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digits = 4 };
    char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(NumberManipulater::RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(NumberManipulater::RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(NumberManipulater::RandomNumber(33, 47));
            break;
        }
        case enCharType::Digits:
        {
            return char(NumberManipulater::RandomNumber(48, 57));
            break;
        }
        }
    }

    string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    string GenerateKey()
    {
        string Key = "";
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
        return Key;
    }

    void GenerateKeys(short NumberOfKeys)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }

    bool GuessPassword(string OriginalPassword)
    {
        string word = "";
        int Counter = 0;

        cout << "\n";
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    Counter++;

                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);

                    cout << "Trial [" << Counter << "] : " << word
                        << endl;

                    if (word == OriginalPassword)
                    {

                        cout << "\nPassword is " << word << "\n";
                        cout << "Found after " << Counter << " Trial(s)\n";
                        return true;
                    }
                    word = "";
                }
            }
        }
        return false;
    }

     string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    short CountNumberOfUpperCase(const string& Password)
    {
        short Count = 0;

        for (int i = 0; i < Password.size(); i++)
        {
            if (isupper(Password[i]))
                Count++;
        }
        return Count;
    }

    short CountNumberOfLowerCase(const string& Password)
    {
        short Count = 0;

        for (int i = 0; i < Password.size(); i++)
        {
            if (islower(Password[i]))
                Count++;
        }
        return Count;
    }

    short CountNumberPunctuation(const string& Password)
    {
        short Count = 0;

        for (int i = 0; i < Password.size(); i++)
        {
            if (ispunct(Password[i]))
                Count++;
        }
        return Count;
    }

    string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
            "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + " Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }

        else
        {
            return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
        }

        return "";
    }

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

    }

    string LowerFirstLetterOfEachWord(string Text)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && isFirstLetter)
            {
                Text[i] = tolower(Text[i]);
            }

            isFirstLetter = (Text[i] == ' ' ? true : false);
            //isFirstLetter = ((Text[i] == ' ') || (ispunct(Text[i])) ? true : false); //Mohammad Abu-Hadhoud
        }

        return Text;

    }

    string UpperAllString(string Text)
    {
        for (short i = 0; i < Text.length(); i++)
        {
            Text[i] = toupper(Text[i]);
        }

        return Text;
    }

    string LowerAllString(string Text)
    {
        for (short i = 0; i < Text.length(); i++)
        {
            Text[i] = tolower(Text[i]);
        }

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

    enum enWhatToCount { CapitalLetters, SmallLetters, Digit, Punctuation, AllLetters };
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

            if (WhatToCount == enWhatToCount::Punctuation && (ispunct(Text[i])))
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

    short CountLetter(string Text, char Letter, bool IsMatchCase = true)
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

    void PrintEachWordInString(string Text)
    {
        string delim = " ";// delimiter

        cout << "\nYour String Words are : \n\n";

        short Pos = 0;
        string sWord;// define a string variable 

        // use find() function to get the position of the delimiters
        while ((Pos = Text.find(delim)) != string::npos) /*Text.npos == std::string::npos == string::npos*/
        {
            sWord = Text.substr(0, Pos);// store the word

            if (sWord != "")
            {
                cout << sWord << endl;
            }

            Text.erase(0, Pos + delim.length());/* erase() until positon and move to next word. */

        }

        if (Text != "")
        {
            cout << Text << endl; // it print last word of the string...
        }


    }

    short CountWordsInString(string Text)
    {
        string delim = " ";// delimiter
        short Counter = 0;
        short Pos = 0;
        string sWord;// define a string variable 

        // use find() function to get the position of the delimiters
        while ((Pos = Text.find(delim)) != string::npos) /*Text.npos == std::string::npos == string::npos*/
        {
            sWord = Text.substr(0, Pos);// store the word

            if (sWord != "")
            {
                Counter++;
            }

            Text.erase(0, Pos + delim.length());/* erase() until positon and move to next word. */

        }

        if (Text != "")
        {
            Counter++; // it Count last word of the string...
        }

        return Counter;
    }

    vector<string> SplitString(string Text, string Delim)
    {
        vector <string> vString;

        short Pos = 0;

        // define a string variable 
        string sWord;//....|| string Token;

        // use find() function to get the position of the delimiter
        while ((Pos = Text.find(Delim)) != std::string::npos)
        {
            sWord = Text.substr(0, Pos);// store the word

            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            Text.erase(0, Pos + Delim.length());/* erase() until positon and move to next word. */

        }

        if (Text != "")
        {
            vString.push_back(Text);// It adds last word of the string...
        }

        return vString;

    }

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

    string JoinString(vector<string> vString, string Delim)
    {
        string Text;

        for (string& S : vString)
        {
            Text = Text + S + Delim;
        }

        return Text.substr(0, Text.length() - Delim.length());
    }

    string JoinString(string ArrString[], short arrLength, string Delim)
    {
        string Text = "";

        for (short i = 0; i < arrLength; i++)
        {
            Text = Text + ArrString[i] + Delim;
        }

        return Text.substr(0, Text.length() - Delim.length());
    }

    string ReverseWordsInString(string Text)
    {
        string Delim = " ";

        vector <string> vString = SplitString(Text, Delim);

        string sWord = "";

        vector <string>::iterator iter;

        iter = vString.end();

        while (iter != vString.begin())
        {
            iter--;
            sWord += *iter + Delim;
        }

        return sWord.substr(0, sWord.length() - Delim.length());

        /*Mohammad Mahmoud Rajab Agha I'm From Deir Al_Zoor   -->   Al_Zoor Deir From I'm Agha Rajab Mahmoud Mohammad */
    }

    string ReplaceWordInStringUsingBuiltInFunction(string Text, string StringToReplace, string sReplaceTo)
    {

        int Pos = Text.find(StringToReplace);

        while (Pos != string::npos)
        {
            Text.replace(Pos, StringToReplace.length(), sReplaceTo);

            Pos = Text.find(StringToReplace);//Find Next....
        }

        return Text;
    }

    string ReplaceWordsInStringUsingSplit(string Text, string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        vector<string> vString = SplitString(Text, " ");

        for (string& S : vString)
        {
            if (MatchCase)
            {
                if (S == StringToReplace)
                {
                    S = sReplaceTo;
                }
            }

            else
            {
                if (LowerAllString(S) == LowerAllString(StringToReplace))
                {
                    S = sReplaceTo;
                }
            }
        }

        return JoinString(vString, " ");

    }

    string ReplaceWords(string Text, string StringToReplace, string sReplaceTo, bool IsMatchCase = true)
    {
    	if (!IsMatchCase)
    	{
    		string tempText = Text;
    		string tempStringToReplace = StringToReplace;
    
    		Text = "";
    		StringToReplace = "";
    
    		for (char& S : tempText)
    		{
    			Text += tolower(S);
    		}
    
    		for (char& S : tempStringToReplace)
    		{
    			StringToReplace += tolower(S);
    		}
    	}
    
    
    	short Pos = Text.find(StringToReplace);
    
    	while (Pos != string::npos)
    	{
    		Text.erase(Pos, StringToReplace.length());
    		Text.insert(Pos, sReplaceTo);
    
    		Pos = Text.find(StringToReplace);
    	}
    
    	return Text;
    }

    string RemovePunctuationsFromString(string Text)
    {
        string S = "";

        for (short i = 0; i < Text.length(); i++)
        {
            if (!ispunct(Text[i]))
            {
                S += Text[i];
            }
        }

        return S;
    }

  enum enOpType { Add = 1, Sub, Mul, Div, MixOp };
    string GetOpTypeSymbol(enOpType OpType)
    {
        string arrOpType[5] = { "+","-","*","/","Mix" };

        return arrOpType[OpType - 1];
    }

    void SetScreenColor(bool Right)
    {
        if (Right)
        {
            system("color 2F");
        }
        else
        {
            system("color 4F");
            cout << "\a";
        }
    }

}
