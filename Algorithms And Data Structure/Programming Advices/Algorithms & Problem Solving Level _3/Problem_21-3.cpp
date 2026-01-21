
#include <iostream>

using namespace std;

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

//void PrintFibonacciSeriesUsingLoop(short Number)
//{
//    int FebNumber = 0;
//    int Prev2 = 1, Prev1 = 0;
//
//    //cout << Prev2 << "    ";
//    //cout << Prev1 << "    ";
//    //cout << "1   ";
//
//    for (short i = 1; i <= Number; i++)
//    {
//        FebNumber = Prev1 + Prev2;
//
//        cout << FebNumber << "    ";
//
//        Prev2 = Prev1;
//        Prev1 = FebNumber;
//    }
//}

int main()
{
    PrintFibonacciSeriesUsingLoop(10);

    system("pause>0");
}