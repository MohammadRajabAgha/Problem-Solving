#include <iostream>

using namespace std;

void PrintNumberFromNToM(int N, int M)
{
    if (N <= M)
    {
        cout << N << "\n";

        PrintNumberFromNToM(N + 1, M);
    }

}

void PrintNumberFromMToN(int M, int N)
{
    if (M>=N)
    {
        cout << M << "\n";

        PrintNumberFromMToN(M - 1, N);
    }

}

int Power(int Base, int POW)
{
    if (POW == 0)
    {
        return 1;
    }

    else
    {
        return Base * Power(Base, POW - 1);
    }

}

int main()
{
    
    PrintNumberFromNToM(10, 20);

    cout << "\n****************************\n";

    PrintNumberFromMToN(30, 10);

    cout << "\n****************************\n";

    cout << Power(2, 4) << "\n\n";

}
