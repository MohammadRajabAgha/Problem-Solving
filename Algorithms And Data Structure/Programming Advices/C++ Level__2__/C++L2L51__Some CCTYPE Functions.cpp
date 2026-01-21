#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{ 
    char x;
    char w;

    x = toupper('a');
    w = tolower('A');

    cout << toupper('a') << endl;
    cout << tolower('A') << endl;


    cout << "_X_Converting a to A: " << x << endl;
    cout << "_W_Converting A to a: " << w << endl;


    // Upper Case (A to Z)
    // returns zero if not, and non zero of yes
    cout << "isupper('A') : " << isupper('A') << endl;


    // Lower Case (a to z)
    // returns zero if not, and non zero of yes  
    cout << "islower('a') : " << islower('a') << endl;


    // Digits (0 to 9)
    // returns zero if not, and non zero of yes 
    cout << "isdigit('9') : " << isdigit('9') << endl;


    // cout << "isdigit('18') : " << isdigit('18') << endl;//Warning ...
    // Punctuation Characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    // returns zero if not, and non zero of yes  
    cout << "ispunct(';') : " << ispunct(';') << endl;
     

    return 0;
}


//#include<iostream>
//#include<string>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//#include<cctype>
//
//using namespace std;
//
//short CountNumberOfUpperCase(const string& Password)
//{
//    short Count = 0;
//
//    for (int i = 0; i < Password.size(); i++)
//    {
//        if (isupper(Password[i]))
//            Count++;
//    }
//    return Count;
//}
//
//short CountNumberOfLowerCase(const string& Password)
//{
//    short Count = 0;
//
//    for (int i = 0; i < Password.size(); i++)
//    {
//        if (islower(Password[i]))
//            Count++;
//    }
//    return Count;
//}
//
//short CountNumberdigits(const string& Password)
//{
//    short Count = 0;
//
//    for (int i = 0; i < Password.size(); i++)
//    {
//        if (isdigit(Password[i]))
//            Count++;
//    }
//    return Count;
//}
//
//short CountNumberPunctuation(const string& Password)
//{
//    short Count = 0;
//
//    for (int i = 0; i < Password.size(); i++)
//    {
//        if (ispunct(Password[i]))
//            Count++;
//    }
//    return Count;
//}
//
//
//string CheckPassword(const string& Password)
//{
//    if (CountNumberOfUpperCase(Password) >= 1 &&
//        CountNumberOfLowerCase(Password) >= 1 &&
//        CountNumberdigits(Password) >= 1 &&
//        CountNumberPunctuation(Password) >= 1 &&
//        Password.size() >= 8
//        )
//
//    {
//        return "Strong Password";
//    }
//    return "Weak Password";
//}
//
//int main()
//{
//    string Password;
//
//    Password = ReadInputs::ReadText("Please enter The Password ? \n");
//
//
//    cout << "The PassWord is : " << CheckPassword(Password) << endl;
//
//
//    return 0;
//}
//