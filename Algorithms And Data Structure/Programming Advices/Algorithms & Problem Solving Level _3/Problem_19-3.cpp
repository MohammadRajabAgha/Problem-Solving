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

int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Min = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Min > Matrix[i][j])
            {
                Min = Matrix[i][j];
            }

        }
    }

    return Min;

}

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Max = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Max < Matrix[i][j])
            {
                Max = Matrix[i][j];
            }

        }
    }

    return Max;

}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,6},{14,3,9} };

    cout << "Matrix1 : \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "Minimum Number is : " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
   
    cout << "Maximum Number is : " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;


    return 0;
}