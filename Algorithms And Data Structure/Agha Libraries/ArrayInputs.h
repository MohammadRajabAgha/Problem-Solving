#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include "ReadInputs.h";
using namespace std;

namespace ArrayInputs
{
    void ReadArray(int arr[100], int& arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;

        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
        cout << endl;
    }

    void FillArrayWithRandomNumbers(int arr[100], int& arrLength, int From, int To)
    {
        cout << "\nEnter Number of elements:\n";

        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = NumberManipulater::RandomNumber(From, To);
        }
    }

    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }

    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = 0;
        Min = arr[0];

        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }

    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;

        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }

        return Sum;
    }

    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    short FindNumberPositionInArray( int arr[100], int arrLength,int Number)
    {
        
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }
        
        return -1;
    }

    int TimesRepeated(int arr[100], int arrLength,int Number)
    {
        int count = 0;
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])
            {
                count++;
            }
        }
        return count;
    }

    bool IsNumberInArray( int arr[100], int arrLength,int Number)
    {
        return FindNumberPositionInArray( arr, arrLength,Number) != -1;
    }

    bool IsPalindromeArray(int arr[100], int Length)
    {
        for (int i = 0; i < Length; i++)
        {
            if (arr[i] != arr[Length - i - 1])
            {
                return false;
            }
        };
        return true;
    }

    int OddCountINArray(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int EvenCountINArray(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int PositiveCountINArray(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    int NegativeCountINArray(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }

    void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
    }
    
    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (NumberManipulater::CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }
        arr2Lenght = --Counter;
    }

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }
    
    void FillArrayWith1toN(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }

    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            NumberManipulater::Swap(arr[NumberManipulater::RandomNumber(1, arrLength) - 1],
                arr[NumberManipulater::RandomNumber(1, arrLength) - 1]);
        }
    }

    void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }

    void FillArrayWithKeys(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = StringManipulation::GenerateKey();
    }

    //
    void AddArrayElement(int arr[100], int& arrLength, int Number)
{
    //its a new element so we need to add the length by 1 
    arrLength++;
    arr[arrLength - 1] = Number;
}

    void InputUserNumbersInArray(int arr[100], int& arrLength, string Message)
{
        bool AddMore = true;
    do
    {
        AddArrayElement(arr, arrLength, ReadInputs::ReadNumber(Message));
        cout << "\nDo you want to add more ? [0]:No,[1]:yes? ";
        cin >> AddMore;
    } while (AddMore);

}


    void CopyEvenNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (arrSource[i] % 2 == 0)
            {
                AddArrayElement(arrDestination, arrDestinationLength, arrSource[i]);
            }
    }

    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement( arrDestination,arrDestinationLength,arrSource[i]);
            }
    }

    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
            if (NumberManipulater::CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                AddArrayElement( arrDestination, arrDestinationLength,arrSource[i]);
            }
    }

// Output: 
// Array 1 elements:  
// 10 10 10 50 50 70 70 70 70 90 
// Array 2 distinct elements:  
// 10 50 70 90 
    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray( arrDestination,DestinationLength,arrSource[i]))
            {
                AddArrayElement( arrDestination,DestinationLength,arrSource[i]);
            }
        };
    }

}









