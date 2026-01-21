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

int SumAllNumbersInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }

    }

    return Sum;

}

bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return (SumAllNumbersInMatrix(Matrix1, Rows, Cols) == SumAllNumbersInMatrix(Matrix2, Rows, Cols));
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2: \n";
    PrintMatrix(Matrix2, 3, 3);


    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
    {
        cout << "Yes : Matrices are equal\n";
    }
    else
    {
        cout << "No : Matrices are NOT equal\n";
    }

    return 0;
}

//                                               Matrix1:
//                                               02    02    04
//                                               02    04    09
//                                               07    07    04
//                                               
//                                               Matrix2:
//                                               02    08    01
//                                               03    01    08
//                                               08    08    02
//                                               
//                                               Yes : Matrices are equal