#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include <vector>


using namespace std;

namespace PrintVector
{
    void PrintNumberInVector(const vector <int>& vNumbers)
    {
        cout << "Vector Numbers : \n\n";

        for (const int& Number : vNumbers)
        {
            cout << Number << "\n";
        }

        cout << endl;
    }




}