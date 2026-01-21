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

bool IsIdentiyMatrix(int Matrix[3][3], short Rows, short Cols)
{
    //Check Diagonal Elements are 1 and NON_Diagonal Elements are 0

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //Check Diagonal Elements...
            if (i == j && Matrix[i][j] != 1)
            {
                return false;
            }

            //Check NON_Diagonal Elements...
            if (i != j && Matrix[i][j] != 0)
            {
                return 0;
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
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };*/
    

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsIdentiyMatrix(Matrix,3,3))
    {
        cout << "Yes : Matrix is identity.\n";
    }
    else
    {
        cout << "No : Matrix is NOT identity.\n";
    }

    return 0;
}


/*

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

bool CheckDiagonal(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j)
            {
                if (Matrix[i][j] != 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool CheckNON_Diagonal(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i != j)
            {
                if (Matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool IsIdentiyMatrix(int Matrix[3][3], short Rows, short Cols)
{
    return (CheckDiagonal(Matrix, Rows, Cols) && CheckNON_Diagonal(Matrix, Rows, Cols));
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    if (IsIdentiyMatrix(Matrix, 3, 3))
    {
        cout << "Yes : Matrix is identity.\n";
    }
    else
    {
        cout << "No : Matrix is NOT identity.\n";
    }

    return 0;
}
                                     
*/


/*
                                              Matrix1:
                                              01    00    00
                                              00    01    00
                                              00    00    01
                                              
                                              Yes : Matrix is identity.
*/



