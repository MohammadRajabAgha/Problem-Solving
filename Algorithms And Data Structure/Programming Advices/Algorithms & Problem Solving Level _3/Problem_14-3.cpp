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
            Matrix[i][j] = RandomNumber(1, 10);
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

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    //Check Diagonal Elements are Equal and NON_Diagonal Elements are 0

    int FirstDiagElement = Matrix[0][0];


    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //Check Diagonal Elements...
            if (i == j && Matrix[i][j] != FirstDiagElement)
            {
                return false;
            }
             

            //Check NON_Diagonal Elements...
            if (i != j && Matrix[i][j] != 0)
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

    int Matrix[3][3];

    /*int Matrix[3][3] =
     {
         {9,0,0},
         {0,9,0},
         {0,0,9}
     };*/

   FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsScalarMatrix(Matrix, 3, 3))
    {
        cout << "Yes : Matrix is Scalar.\n";
    }

    else
    {
        cout << "No : Matrix is NOT Scalar.\n";
    }

    return 0;
}
//  Lesson14/3                                Scalar Matrr=ix

/*
                                              Matrix1:
                                              09   00   00
                                              00   09   00
                                              00   00   09

                                              Yes : Matrix is Scalar.
*/



