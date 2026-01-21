#include <iostream>
#include<cstdlib>
#include <iomanip>
#include<cmath>

using namespace std;

int RandomNumber(int From, int To)
{
    int  randNum = 0;

    randNum = From + rand() % (To - From + 1);

    return  randNum;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // cout << setw(3) << Arr[i][j] << "     ";
            printf(" %0*d   ", 2, Matrix[i][j]);
        }

        cout << "\n";
    }

    cout << endl;

}

bool IsPalindromMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)//important to do Cols / 2 
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
            {
                return false;
            }
        }
    }

    return true;

}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

    cout << "Matrix : \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsPalindromMatrix(Matrix, 3, 3))
    {
        cout << "Yes : Matrix is Palindrom.\n";
    }

    else
    {
        cout << "No : Matrix is NOT Palindrom.\n";
    }

    return 0;
}

/*
                                      Matrix:
                                      01    02    01
                                      05    05    05
                                      07    03    07
                                      
                                      Yes : Matrix is Palindrom.
  */                                    