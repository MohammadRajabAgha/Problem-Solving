#pragma once

#pragma warning(disable : 4996)

#ifndef NUMBERMANIPULATER_H
#define NUMBERMANIPULATER_H

#include<iostream>
#include<cctype>
#include<cstdio>
#include<string>
#include <cstdlib>

using namespace std;


namespace NumberManipulater
{
    enum enNumberType { Odd = 1, Even = 2 };
    enNumberType CheckNumberType(int Num)
    {
        int Result = Num % 2;
        if (Result == 0)
            return enNumberType::Even;
        else
            return enNumberType::Odd;
    }

    enum enPassFail { PASS = 1, FAIL = 2 };
    enPassFail CheckMark(int Mark)
    {

        if (Mark >= 50)
            return enPassFail::PASS;
        else
            return enPassFail::FAIL;

    }

    enPassFail CheckAverage(float Average)
    {
        if (Average >= 50)
            return enPassFail::PASS;
        else
            return enPassFail::FAIL;
    }

    int ReverseNumber(int Number)
    {
        int Remainder = 0;
        int Number2 = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }

        return Number2;
    }

    bool IsPalindromeNumber(int Number)
    {
        return Number == ReverseNumber(Number);
    }

    int MaxOf2Numbers(int Num1, int Num2)
    {
        return (Num1 > Num2) ? Num1 : Num2;
    }

    int MaxOfNumbers(int Num1, int Num2, int Num3 = 0, int Num4 = 0)
    {
        int Result1 = MaxOf2Numbers(Num1, Num2);
        int Result2 = MaxOf2Numbers(Num3, Num4);

        if (Result1 > Result2)
            return Result1;

        else
            return Result2;
    }

    void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    bool IsEven(int Number)
    {
        return 	(Number % 2 == 0);
    }

    bool IsOdd(int Number)
    {
        return (Number % 2 != 0);
    }

    bool IsNumberInRange(int Number, int From, int To)
    {
        return Number >= From && Number <= To;
    }

    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
    enPrimNotPrime CheckPrime(int Number)
    {
        int M = round(Number / 2);

        if (Number == 2)
            return enPrimNotPrime::Prime;

        if (Number == 0 || Number == 1)
            return enPrimNotPrime::NotPrime;

        for (int Counter = 2; Counter <= M; Counter++)
        {

            if (Number % Counter == 0)
                return enPrimNotPrime::NotPrime;
        }
        return  enPrimNotPrime::Prime;;
    }

    int RandomNumber(int From, int To)
    {
        int randNum = 0;

        randNum = From + rand() % (To - From + 1);

        return randNum;
    }

    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int FreqCount = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;

            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }

    string NumberSignalType(int Number)
    {
        string  Result = "";

        Result = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");

        return Result;
    }

    float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }

    short CountNumberdigits(const string& Password)
    {
        short Count = 0;

        for (int i = 0; i < Password.size(); i++)
        {
            if (isdigit(Password[i]))
                Count++;
        }
        return Count;
    }

    int MySum(int Num1, int Num2, int Num3 = 0, int Num4 = 0)
    {
        return (Num1 + Num2 + Num3 + Num4);
    }

    float MySum(float Num1, float Num2, float Num3 = 0, float Num4 = 0)
    {
        return (Num1 + Num2 + Num3 + Num4);
    }

    double MySum(double Num1, double Num2, double Num3 = 0, double Num4 = 0)
    {
        return (Num1 + Num2 + Num3 + Num4);
    }

    float CalculateHalfNumber(int Num)
    {
        return (float)Num / 2;
    }

    float CalculateAverage(int Sum, short NumberOfItem)
    {
        return (float)Sum / NumberOfItem;
    }

    int Factorial(int Num)
    {
        int Factorial = 1;
        for (int Counter = Num; Counter >= 1; Counter--)
        {
            Factorial *= Counter;
        }
        return Factorial;
    }

    int SumOfDigits(int Number)
    {
        int Sum = 0, Remainder = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum = Sum + Remainder;
        }

        return Sum;
    }

    int MyRound(float Number)
    {
        int IntPart;
        IntPart = int(Number);

        float FractionsPart = GetFractionPart(Number);

        if (FractionsPart >= .5)
        {
            if (Number > 0)
            {
                return ++IntPart;
            }
            else
            {
                return --IntPart;
            }
        }
        else
        {
            return IntPart;
        }
    }

    int MyFloor(float Number)
    {
        if (Number > 0)
            return int(Number);
        else
            return int(Number) - 1;
    }

    int MyCeil(float Number)
    {
        if (fabs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(Number) + 1;
            else
                return int(Number);
        }
        else
        {
            return int(Number);
        }
    }

    enum enOpType { Add = 1, Sub, Mul, Div, MixOp };
    int SampleCalculater(int Number1, int Number2, enOpType OpType)
    {
        switch (OpType)
        {
        case Add:
            return Number1 + Number2;
            break;
        case Sub:
            return Number1 - Number2;
            break;
        case Mul:
            return Number1 * Number2;
            break;
        case Div:
            return Number1 / Number2;
            break;

        default:
            return Number1 + Number2;
            break;
        }
    }

    void PrintTrueFalseResult(bool Boolean)
    {
        if (Boolean == 0)
            cout << "False\n";
        else
            cout << "True\n";
    }

    void PrintMarkAverageResults(enPassFail PassFail, string Message)
    {
        if (PassFail == enPassFail::PASS)
            cout << "\n You Passed \n";
        else
            cout << "\n You Faild \n";

    }

    bool isPerfectNumber(int Number)
    {
        int Sum = 0;

        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }

        return Number == Sum;
    }

    void PrintDigitsInReversedOrder(int Number)
    {
        int Remainder = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    void PrintAllDigitsFrequencey(int Number)
    {
        cout << endl;

        for (int i = 0; i < 10; i++)
        {
            short DigitFrequency = 0;

            DigitFrequency = NumberManipulater::CountDigitFrequency(i, Number);
            if (DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequencey is "
                    << DigitFrequency << " Time(s).\n";
            }
        }
    }

    void PrintFibonacciSeriesUsingLoop(short Number)
    {
        int FebNumber = 0;
        int Prev2 = 0, Prev1 = 1;

        //cout << Prev2 << "    ";
        //cout << Prev1 << "    ";
        cout << "1   ";

        for (short i = 2; i <= Number; i++)
        {
            FebNumber = Prev1 + Prev2;

            cout << FebNumber << "    ";

            Prev2 = Prev1;
            Prev1 = FebNumber;
        }
    }

    void PrintFibonacciSeriesUsingRecurssion(short Number, int Prev1, int Prev2)
    {
        int FebNumber = 0;

        //Prev1=0
        //Prev2=1

        if (Number > 0)
        {
            FebNumber = Prev1 + Prev2;

            cout << FebNumber << "    ";

            Prev2 = Prev1;
            Prev1 = FebNumber;

            PrintFibonacciSeriesUsingRecurssion(Number - 1, Prev1, Prev2);
        }
    }
}

#endif // NUMBERMANIPULATER_H