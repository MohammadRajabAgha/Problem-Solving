#include <iostream>

using namespace std;

void PrintFibonacciSeriesUsingRecurssion(short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;

        cout << FebNumber << "    ";

        Prev2 = Prev1;
        Prev1 = FebNumber;

        PrintFibonacciSeriesUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    //PrintFibonacciSeriesUsingRecurssion(10, 1, 0);//    1    2    3    5    8    13    21    34    55    89
   PrintFibonacciSeriesUsingRecurssion(10, 0, 1);//       1    1    2    3    5     8    13    21    34    55

   //Prev1=0
   //Prev2=1

    system("pause>0");
}



//#include <iostream>
//
//using namespace std;
//
//void PrintFibonacciSeriesUsingRecurssion(int Prev2, int Prev1, short Count, short Number)
//{
//    if (Count == 10)
//        return;
//
//    else
//    {
//        if (Count == 1)
//        {
//            cout << Prev1 << "    ";
//        }
//
//        cout << Prev1 + Prev2 << "    ";
//        PrintFibonacciSeriesUsingRecurssion(Prev1, Prev1 + Prev2, Count + 1, Number);
//    }
//}
//
//int main()
//{
//    PrintFibonacciSeriesUsingRecurssion(0, 1, 1, 10);
//
//    system("pause>0");
//}