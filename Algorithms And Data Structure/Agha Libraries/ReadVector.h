#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include "ReadInputs.h"


using namespace std;

namespace ReadVector
{
    void ReadNumberInVector(vector <int>& vNumbers,string Message)
    {
        char ReadMore = 'Y';
        int Number = 0;

        while (ReadMore == 'Y' || ReadMore == 'y')
        {
            Number = ReadInputs::ReadNumber(Message);

            vNumbers.push_back(Number);

            cout << "\nDo you Want To Add More ? ";
            cin >> ReadMore;

        }
        cout << endl;
    }

    void ReadTextInVector(vector <string>& vText, string Message)
    {
        char ReadMore = 'Y';
        string Line = "";

        while (ReadMore == 'Y' || ReadMore == 'y')
        {
            Line = ReadInputs::ReadText(Message);

            vText.push_back(Line);

            cout << "\nDo you Want To Add More ? ";
            cin >> ReadMore;

        }
        cout << endl;
    }

}
