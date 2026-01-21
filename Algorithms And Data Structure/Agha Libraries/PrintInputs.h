#pragma once

#pragma warning(disable : 4996)

#include<iostream>
using namespace std;

namespace PrintInputs
{
     
    void PrintNumber(int Number,string Message)
    {
        cout << Message << Number << "\n";
    }

    void PrintFloatNumber(float Number,string Message)
    {
        cout << Message << Number << "\n";
    }

    void PrintText(string Text,string Message)
    {
        cout << Message << Text << "\n";
    }

    void PrintChar( char Character,string Message)
    {
        cout << Message << Character << "\n";
    }

}

