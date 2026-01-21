#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include "ArrayInputs.h"
using namespace std;

namespace PrintArray
{

    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }

    void PrintNumberPositionandOrder( int arr[100], int arrLength,int Number)
    {
        short NumberPosition = ArrayInputs::FindNumberPositionInArray( arr, arrLength,Number);

        if (NumberPosition == -1)
            cout << "The number is not found :-(\n";
        else
        {
            cout << "The number found at position: ";
            cout << NumberPosition << endl;
            cout << "The number found its order: ";
            cout << NumberPosition + 1 << endl;
        }
    }

    void PrintFoundOrNotFound( int arr[100], int arrLength,int Number)
    {

        cout << "\nNumber you are looking for is: " << Number << endl;

        if (!(ArrayInputs::IsNumberInArray(arr, arrLength,Number)))
            cout << "No, The number is not found :-(\n";
        else
        {
            cout << "Yes, it is found :-)\n";
        }
    }

    void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n";
    }

}